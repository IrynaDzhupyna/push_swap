#include <stdio.h>

typedef struct Node
{
    int *data;
    struct Node *next;
}   node;

//create a node

node    *new_node(int *data)
{
    node    *new_node;

    if (!data)
        return (NULL);
    new_node = malloc(sizeof(node));
    if (!new_node)
        return (NULL);
    new_node->data = data;
    new_node->next = NULL;
    return (new_node);
}

//add back
void    node_add_back(node *list)
{
    node    *current;

    if (!list)
        return ;
    current = list;
    while (current->next)
    {
        current = current->next;
    }
}
int main(void)
{
    int num;
    node    **list;

    num = 0;



}