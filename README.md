# Push_swap

## Description
sort data in stack using a limited set of instructions, aiming to achieve the lowest possible number of actions.

What we have:
	- set of int values;
	- 2 stacks;
	- a set of instructions to manipulate both stacks.

What I need to do:
	- write c program push_swap
	- program calculates and displays the shortest sequence of Push_swap instructions needed to sort the given integers.

## Concept of complaxity
**Time complaxity** - how long it takes.
**Memory/space complaxity** - how much RAM it uses.

Stack - LIFO(last in first out)

**Rules:**
- There are 2 stacks (a & b)
- At the beginning:
	- a contains a ramdom munber of unique int(negative or/and positive)
	- b is empty
- The goal: 
	- sort int in ascending orger with the lowest possible num of operations
	- display the shortest sequence of instructions needed to sort stack (smallest num on top)
- Instructions must be separated by '\n'
- If no param, program return the prompt.
- if Error -> display "Error\n" on standard error
	Possible Errors:
		- some args not int;
		- some args exceeding the int limits (more INT_MIN/INT_MAX);
		- duplicates;

Program checker_OS (resources of the project)  should display OK, if not - list of instructions that doesn't sort the numbers

• For maximum project validation (100%) and eligibility for bonuses, you must:
	◦ Sort 100 random numbers in fewer than 700 operations.
	◦ Sort 500 random numbers in no more than 5500 operations.
• For minimal project validation (which implies a minimum grade of 80%), you
can succeed with different averages:
	◦ 100 numbers in under 1100 operations and 500 numbers in under
8500 operations
	◦ 100 numbers in under 700 operations and 500 numbers in under
11500 operations
	◦ 100 numbers in under 1300 operations and 500 numbers in under
5500 operations

### Choosing Data Type
Linked List vs Array
- how much space this data type take
- how easy to mainpulate, how fast to access an element

