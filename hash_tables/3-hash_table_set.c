#include "hash_tables.h"
#include <string.h>

/**
 * hash_table_set - adds an element to the hash table
 * @ht: the hash table
 * @key: the key, cannot be empty
 * @value: the value associated with the key, duplicated
 *
 * Return: 1 on success, 0 on failure
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
unsigned long int index;
hash_node_t *node, *tmp;
char *val_copy;

if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
return (0);

index = key_index((const unsigned char *)key, ht->size);
tmp = ht->array[index];

/* Check if key already exists, update value */
while (tmp != NULL)
{
if (strcmp(tmp->key, key) == 0)
{
val_copy = strdup(value);
if (val_copy == NULL)
return (0);
free(tmp->value);
tmp->value = val_copy;
return (1);
}
tmp = tmp->next;
}

/* Key not found, create new node */
node = malloc(sizeof(hash_node_t));
if (node == NULL)
return (0);

node->key = strdup(key);
if (node->key == NULL)
{
free(node);
return (0);
}

node->value = strdup(value);
if (node->value == NULL)
{
free(node->key);
free(node);
return (0);
}

/* Insert at beginning of list (chaining for collisions) */
node->next = ht->array[index];
ht->array[index] = node;

return (1);
}
