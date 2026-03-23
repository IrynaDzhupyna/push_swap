//DIDN`T USE THIS FUNCTION
//Not sure about this
/*s_node  biggest_node(s_node **stack_head)
{
    s_node  *current;
    s_node  *max;

    current = *stack_head;
    while (current->value > current->next->value)
        current = current->next;
    max = current;
    return (*max);
}*/

/*s_node  *smallest_node(s_node **stack_head)
{
    s_node  *min;
    s_node  *current;

    current = *stack_head;
    min = current;
    
    while (current->next)
    {
        if (current->value > current->next->value)
            min = current->next;
        current = current->next;
    }
    return (min);
}*/