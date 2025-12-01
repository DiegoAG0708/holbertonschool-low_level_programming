#include "hash_tables.h"
#include <string.h>

/**
 * create_hash_node - creates a new hash node
 * @key: key string
 * @value: value string
 *
 * Return: pointer to new node, or NULL on failure
 */
hash_node_t *create_hash_node(const char *key, const char *value)
{
hash_node_t *node;

node = malloc(sizeof(hash_node_t));
if (node == NULL)
return (NULL);

node->key = strdup(key);
if (node->key == NULL)
{
free(node);
return (NULL);
}

node->value = strdup(value);
if (node->value == NULL)
{
free(node->key);
free(node);
return (NULL);
}

node->next = NULL;
return (node);
}

/**
 * update_existing_node - updates value of an existing key
 * @head: head of linked list
 * @key: key to search
 * @value: new value to assign
 *
 * Return: 1 if updated, 0 if not found or failed
 */
int update_existing_node(hash_node_t *head, const char *key, const char *value)
{
char *val_copy;

while (head != NULL)
{
if (strcmp(head->key, key) == 0)
{
val_copy = strdup(value);
if (val_copy == NULL)
return (0);
free(head->value);
head->value = val_copy;
return (1);
}
head = head->next;
}
return (0);
}

/**
 * hash_table_set - adds or updates a key/value in the hash table
 * @ht: hash table
 * @key: key string (non-empty)
 * @value: value string (can be empty)
 *
 * Return: 1 on success, 0 on failure
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
unsigned long int index;
hash_node_t *node;

if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
return (0);

index = key_index((const unsigned char *)key, ht->size);

if (update_existing_node(ht->array[index], key, value))
return (1);

node = create_hash_node(key, value);
if (node == NULL)
return (0);

node->next = ht->array[index];
ht->array[index] = node;

return (1);
}
