#include "main.h"

/**
* add_node_at_end - Add a node at the end of a linked list
* @head: A pointer to the head of the linked list
* @str: The string to be stored in the new node
* @num: The integer value to be stored in the new node
*
* Return: A pointer to the newly added node,
*         or NULL if memory allocation fails or head is NULL.
*/
list_t *add_node_at_end(list_t **head, const char *str, int num)
{
	list_t *new_node, *current_node;

	if (head == NULL)
		return (NULL);

	current_node = *head;
	new_node = malloc(sizeof(list_t));
	if (new_node == NULL)
		return (NULL);

	_memset((void *)new_node, 0, sizeof(list_t));
	new_node->number = num;

	if (str != NULL)
	{
		new_node->string = custom_strdup(str);

		if (new_node->string == NULL)
		{
			free(new_node);
			return (NULL);
		}
	}

	if (current_node != NULL)
	{
		while (current_node->next != NULL)
			current_node = current_node->next;
		current_node->next = new_node;
	}
	else
		*head = new_node;

	return (new_node);
}


/**
* del_node_at_index - Deletes a node at a given index in a linked list
* @head: A pointer to the head of the linked list
* @index: The index of the node to delete
*
* Return: 1 if deletion is successful, 0 otherwise
*/
int del_node_at_index(list_t **head, unsigned int index)
{
	if (!head || !*head)
		return (0);

	if (index == 0)
	{
		list_t *node_to_delete = *head;
		*head = (*head)->next;
		free(node_to_delete->str);
		free(node_to_delete);
		return (1);
	}

	list_t *current_node = *head;
	list_t *previous_node = NULL;
	unsigned int current_index = 0;

	/* Traverse the linked list to find the node at the given index */
	while (current_node)
	{
		if (current_index == index)
		{
			previous_node->next = current_node->next;
			free(current_node->str);
			free(current_node);
			return (1);
		}

		previous_node = current_node;
		current_node = current_node->next;
		current_index++;
	}
	/* Deletion failure: Node not found at the given index */
	return (0);
}


/**
 * _delimiter - Checks if a character is a delimiter
 * @charact: The character to check
 * @delimiters: The string of delimiters
 *
 * Return: 1 if the character is a delimiter, 0 otherwise
 */
int _delimiter(char charact, char *delimiters)
{
	while (*delimiters)
	{
		if (*delimiters++ == charact)
			return (1);
	}
	return (0);
}


/**
 * unset_env - Unsets an environment variable from the list
 * @info: Pointer to the information struct
 * @var: The variable to unset
 *
 * Return: 1 if unset operation is successful, 0 otherwise
 */
int unset_env(info_t *info, char *var)
{
	char *prefix_match;
	list_t *current_node = info->env;
	size_t index = 0;

	if (!current_node || !var)
		return (0);

	while (current_node)
	{
		prefix_match = starts_with(current_node->str, var);

		if (prefix_match && *prefix_match == '=')
		{
			info->env_changed = del_node_at_index(&(info->env), index);
			index = 0;
			current_node = info->env;
			continue;
		}

		current_node = current_node->next;
		index++;
	}
	return (info->env_changed);
}


/**
 * set_env - Sets or updates an environment variable
 * @info: Pointer to the information struct
 * @var: The variable to set or update
 * @value: The value of the variable
 *
 * Return: 0 on success, 1 on failure
 */
int set_env(info_t *info, char *var, char *value)
{
	char *env_str = NULL;
	list_t *node;
	char *prefix_match;

	if (!var || !value)
		return (0);

	env_str = malloc(custom_strlen(var) + custom_strlen(value) + 2);
	if (!env_str)
		return (1);

	custom_strcpy(env_str, var);
	custom_strcat(env_str, "=");
	custom_strcat(env_str, value);

	node = info->env;
	while (node)
	{
		prefix_match = starts_with(node->str, var);
		if (prefix_match && *prefix_match == '=')
		{
			free(node->str);
			node->str = env_str;
			info->env_changed = 1;
			return (0);
		}
		node = node->next;
	}

	add_node_at_end(&(info->env), env_str, 0);

	free(env_str);

	info->env_changed = 1;

	return (0);
}


/**
 * convert_linked_list_to_array - Converts a linked list to an array of strings
 * @list_head: Pointer to the head of the linked list
 *
 * Return: Array of strings on success, NULL on failure
 */
char **convert_linked_list_to_array(list_t *list_head)
{
	list_t *current_node = list_head;
	size_t num_nodes = list_len(list_head);
	char **str_array;
	char *str;
	size_t i, j;

	if (!list_head || !num_nodes)
		return (NULL);

	str_array = malloc(sizeof(char *) * (num_nodes + 1));
	if (!str_array)
		return (NULL);

	for (i = 0; current_node; current_node = current_node->next, i++)
	{
		str = malloc(custom_strlen(current_node->str) + 1);
		if (!str)
		{
			for (j = 0; j < i; j++)
				free(str_array[j]);
			free(str_array);
			return (NULL);
		}

		custom_strcpy(str, current_node->str);
		str_array[i] = str;
	}

	str_array[i] = NULL;
	return (str_array);
}



/**
 * _memset - Fills first n bytes of memory area pointed to by dest
 *           with the constant byte value.
 * @dest: Pointer to the memory area to be filled.
 * @value: Value to be set.
 * @bytes: Number of bytes to be filled.
 *
 * Return: Pointer to the filled memory area.
 */
char *_memset(char *dest, char value, unsigned int bytes)
{
	unsigned int index;

	for (index = 0; index < bytes; index++)
		dest[index] = value;
	return (dest);
}
