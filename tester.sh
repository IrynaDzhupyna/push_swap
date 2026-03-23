#!/bin/bash

EXEC=./push_swap
CHECKER=./checker

test_case() {
    ARG="$1"

    RESULT=$($EXEC $ARG | $CHECKER $ARG)
    OPS=$($EXEC $ARG | wc -l)

    if [ "$RESULT" != "OK" ]; then
        echo "❌ FAIL: $ARG"
        echo "Result: $RESULT"
        exit 1
    else
        echo "✅ OK: $ARG | ops: $OPS"
    fi
}

echo "---- TESTING 2 NUMBERS ----"
test_case "1 2"
test_case "2 1"

echo "---- TESTING 3 NUMBERS ----"
test_case "1 2 3"
test_case "1 3 2"
test_case "2 1 3"
test_case "2 3 1"
test_case "3 1 2"
test_case "3 2 1"

echo "---- TESTING 4 NUMBERS ----"
test_case "1 2 3 4"
test_case "1 2 4 3"
test_case "1 3 2 4"
test_case "1 3 4 2"
test_case "1 4 2 3"
test_case "1 4 3 2"

test_case "2 1 3 4"
test_case "2 1 4 3"
test_case "2 3 1 4"
test_case "2 3 4 1"
test_case "2 4 1 3"
test_case "2 4 3 1"

test_case "3 1 2 4"
test_case "3 1 4 2"
test_case "3 2 1 4"
test_case "3 2 4 1"
test_case "3 4 1 2"
test_case "3 4 2 1"

test_case "4 1 2 3"
test_case "4 1 3 2"
test_case "4 2 1 3"
test_case "4 2 3 1"
test_case "4 3 1 2"
test_case "4 3 2 1"

echo "🎉 ALL TESTS PASSED"
