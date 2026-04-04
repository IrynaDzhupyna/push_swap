#!/bin/bash

NAME=./push_swap
CHECKER=./checker_linux

RED="\033[0;31m"
GREEN="\033[0;32m"
YELLOW="\033[1;33m"
NC="\033[0m"

valid_total=0
valid_pass=0
invalid_total=0
invalid_pass=0
leak_total=0
leak_pass=0

run_valid() {
	input="$1"
	valid_total=$((valid_total + 1))
	out=$($NAME $input 2>/dev/null)
	if [ -x "$CHECKER" ]; then
		res=$(echo "$out" | $CHECKER $input 2>/dev/null)
		if [ "$res" = "OK" ]; then
			echo -e "${GREEN}[OK]${NC} valid: $input"
			valid_pass=$((valid_pass + 1))
		else
			echo -e "${RED}[FAIL]${NC} valid: $input -> checker: $res"
		fi
	else
		echo -e "${YELLOW}[SKIP]${NC} checker not found: $input"
	fi
}

run_invalid() {
	input="$1"
	invalid_total=$((invalid_total + 1))
	err=$($NAME $input 2>&1 >/dev/null)
	if [ "$err" = "Error" ]; then
		echo -e "${GREEN}[OK]${NC} invalid: $input"
		invalid_pass=$((invalid_pass + 1))
	else
		echo -e "${RED}[FAIL]${NC} invalid: $input -> got: '$err'"
	fi
}

run_noarg() {
	err=$($NAME 2>&1)
	if [ -z "$err" ]; then
		echo -e "${GREEN}[OK]${NC} no args"
	else
		echo -e "${RED}[FAIL]${NC} no args -> got: '$err'"
	fi
}

run_leak() {
	input="$1"
	leak_total=$((leak_total + 1))
	log=$(mktemp)
	valgrind --leak-check=full --show-leak-kinds=all \
		--errors-for-leak-kinds=all --error-exitcode=42 \
		$NAME $input >/dev/null 2>"$log"
	status=$?
	if [ $status -eq 42 ]; then
		echo -e "${RED}[LEAK]${NC} $input"
		cat "$log" | grep -E "definitely lost|indirectly lost|possibly lost|ERROR SUMMARY"
	else
		echo -e "${GREEN}[OK]${NC} leak: $input"
		leak_pass=$((leak_pass + 1))
	fi
	rm -f "$log"
}

echo "========== NO ARG TEST =========="
run_noarg

echo
echo "========== VALID INPUT TESTS =========="
run_valid "1"
run_valid "2 1"
run_valid "1 2"
run_valid "3 2 1"
run_valid "2 3 1"
run_valid "3 1 2"
run_valid "0 -1 5 2"
run_valid "2147483647 -2147483648 0"
run_valid "\"3 2 1\""
run_valid "\"1 2 3 4 5\""

echo
echo "========== INVALID INPUT TESTS =========="
run_invalid "\"\""
run_invalid "\"   \""
run_invalid "\"+\""
run_invalid "\"-\""
run_invalid "\"--1\""
run_invalid "\"++1\""
run_invalid "\"1a\""
run_invalid "\"a\""
run_invalid "\"2147483648\""
run_invalid "\"-2147483649\""
run_invalid "1 2 2"
run_invalid "\"1 2 2\""
run_invalid "\"1 --2 3\""
run_invalid "\"1 + 2\""

echo
echo "========== LEAK TESTS =========="
run_leak "\"\""
run_leak "\"   \""
run_leak "\"1\""
run_leak "1"
run_leak "\"3 2 1\""
run_leak "3 2 1"
run_leak "\"2147483648\""
run_leak "\"1 2 2\""

echo
echo "========== SUMMARY =========="
echo "Valid:   $valid_pass / $valid_total"
echo "Invalid: $invalid_pass / $invalid_total"
echo "Leaks:   $leak_pass / $leak_total"
