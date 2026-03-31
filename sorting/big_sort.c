
#include "push_swap.h"

/*int bits_counter(int max_index)
{
    int bits_needed;
    int temp;

    temp = max_index;
    bits_needed = 0;
    while (temp != 0)
    {
        bits_needed++;
        temp = temp >> 1;
    }
    return (bits_needed);
}*/

int bits_counter(int max_index)
{
    int bits;

    bits = 0;
    while ((max_index >> bits) != 0)
    {
        bits++;
    }
        return (bits);
}

void    big_sort(s_node **stack_head_a, s_node **stack_head_b, int stack_size)
{
    int max_index;
    int bits_needed;
    int num;
    int i;
    int j;

    max_index = stack_size - 1;
    bits_needed = bits_counter(max_index);
    i = 0;
    while (i < bits_needed)
    {
        j = 0;
        while (j < stack_size)
        {
            num = (*stack_head_a)->index;
            if (((num >> i) & 1) == 1)
            {
                ra(stack_head_a);
                /*printf("\nSTACK A IS:\n");
                print_stack(*stack_head_a);
                printf("\nSTACK B IS:\n");
                print_stack(*stack_head_b);*/
            }
            else
            {
                pb(stack_head_a, stack_head_b);
                /*printf("\nSTACK A IS:\n");
                print_stack(*stack_head_a);
                printf("\nSTACK B IS:\n");
                print_stack(*stack_head_b);*/
            }
            j++; 
        }
        while (*stack_head_b)
            pa(stack_head_a, stack_head_b);
        i++;
    }
}


















































































/*void    big_sort(s_node **stack_head_a, s_node **stack_head_b, int stack_size)
{
    int i;
    int j;
    int bits_needed;
    int max_index;

    i = 0;
    bits_needed = 0;
    max_index = stack_size - 1;
    while ((max_index >> bits_needed) != 0)
        bits_needed++;
    while (i < bits_needed)
    {
        j = 0;
        while (j < stack_size)
        {
            max_index = (*stack_head_a)->index;
            if (((max_index >> i) & 1) == 1)
                ra(stack_head_a);
            else
                pb(stack_head_a, stack_head_b);
            j++;
        }
        //min_node
        while (*stack_head_b != NULL)
        {
            pa(stack_head_a, stack_head_b);
        }
        i++;
    }
}*/
