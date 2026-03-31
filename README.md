### Why linked list

- Stack overflow is occurs only when memory is exhausted
- memory allocation happens at run time, memory efficiency.

New_node's next pointer is set to the current top.
The top pointer is updated to piont to this new node.

AI Usage
- making a road map for the project
- and checking the pit falls

RADIX based on LSB(Least Significant Bite)

Memory Leaks Check
- make
- valgrind --leak-check=full ./push_swap "3 2 1"
or
- valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./push_swap "3 2 1"