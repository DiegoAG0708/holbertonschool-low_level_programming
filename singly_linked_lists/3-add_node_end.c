#include <stdlib.h>
#include <string.h>
#include "lists.h"

/**
*add_node_end - Adds a new node at the end of a list_t list
*@head: Address of the pointer to the head node
*@str: String to duplicate into the new node
*
*Return: Address of the new element, or NULL on failure
*/
list_t *add_node_end(list_t **head, const char *str)
{
list_t *new_node;
list_t *tail;
char *dup;
unsigned int len = 0;

if (head == NULL || str == NULL)
return (NULL);

dup = strdup(str);
if (dup == NULL)
return (NULL);

while (dup[len] != '\0')
len++;

new_node = malloc(sizeof(list_t));
if (new_node == NULL)
{
free(dup);
return (NULL);
}

new_node->str = dup;
new_node->len = len;
new_node->next = NULL;

if (*head == NULL)
{
*head = new_node;
return (new_node);
}

tail = *head;
while (tail->next != NULL)
tail = tail->next;

tail->next = new_node;

return (new_node);
}
