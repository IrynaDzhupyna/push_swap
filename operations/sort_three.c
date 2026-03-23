void	sort_three(s_node **h)
{
	s_node	*first;
	s_node	*second;
	s_node	*third;

	if (!h || !*h || !(*h)->next || !(*h)->next->next)
		return ;
	first = *h;
	second = first->next;
	third = second->next;
	if (first->value < second->value && second->value < third->value)
		return ;
	if (first->value > second->value && second->value < third->value && first->value < third->value)
		swap(h);
	else if (first->value > second->value && second->value > third->value)
	{ swap(h); reverse_rotate(h); }
	else if (first->value > second->value && second->value < third->value && first->value > third->value)
		rotate(h);
	else if (first->value < second->value && second->value > third->value && first->value < third->value)
	{ swap(h); rotate(h); }
	else
		reverse_rotate(h);
}