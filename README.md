*This project has been created as part of the 42 curriculum by irdzhupy.*

# push_swap

## Description

push_swap is a sorting algorithm project where the goal is to sort a stack of integers using a limited set of operations and the smallest number of moves possible.

The program takes a list of integers as input and outputs a sequence of operations that sorts them in ascending order.

This implementation uses:
- A **small sort** algorithm optimized for stacks of up to 5 elements
- A **big sort** algorithm based on **Radix Sort**, using indexed values for efficiency

The objective is to ensure correctness, handle all edge cases, and minimize the number of operations.

## Instructions

### Compilation

make

### Usage

./push_swap 3 2 1

or

./push_swap "3 2 1"

### Example Output

sa  
rra

### Testing with checker

./push_swap 3 2 1 | ./checker_linux 3 2 1

### Memory check

valgrind --leak-check=full --show-leak-kinds=all ./push_swap "3 2 1"

## Resources

- 42 push_swap subject documentation  
- Radix sort algorithm explanations  
- Linked list and stack data structure references  
- Valgrind documentation  

### Use of AI

AI tools (ChatGPT) were used to:
- Understand radix sort and bitwise operations  
- Refactor code to comply with Norm 42  
- Debug memory leaks using Valgrind  
- Improve code structure and readability  

All implementation logic and final decisions were written and verified manually.

## Additional Information

### Supported Operations

sa, sb, ss  
pa, pb  
ra, rb, rr  
rra, rrb, rrr  

### Features

- Input validation (invalid characters, duplicates, overflow)  
- Small sort for stacks up to 5 elements  
- Radix sort for larger inputs  
- Memory-safe implementation (no leaks)  

### Technical Choices

- Linked list implementation for stacks  
- Index-based sorting for radix algorithm  
- Modular code structure  
