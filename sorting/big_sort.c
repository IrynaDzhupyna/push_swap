
#include "push_swap.h"

void    big_sort(s_node **stack_head_a, s_node **stack_head_b, int size)
{
    int i;
    int j;
    int max_bits;
    int num;

    i = 0;
    max_bits = 0;
    num = size - 1;
    while ((num >> max_bits) != 0)
        max_bits++;
    while (i < max_bits)
    {
        j = 0;
        while (j < size)
        {
            num = (*stack_head_a)->index;
            if (((num >> i) & 1) == 1)
                ra(stack_head_a);
            else
                pb(stack_head_a, stack_head_b);
            j++;
        }
        while (*stack_head_b != NULL)
            pa(stack_head_b, stack_head_a);
        i++;
    }
}
