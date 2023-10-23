#include <stdio.h>
#include "lists.h"

/**
 * is_palindrome - checks if a singly linked list is a palindrome
 * @head: pointer to a pointer to the head of the list
 * Return: 1 if the list is a palindrome, 0 otherwise
 */
int is_palindrome(listint_t **head)
{
    if (*head == NULL)
        return (1);

    listint_t *current = *head;
    listint_t *array[4096];
    int i, j;

    for (i = 0, j = 0; current != NULL; i++, j++, current = current->next)
        array[i] = current;

    for (i = 0, j--; i < j; i++, j--)
    {
        if (array[i]->n != array[j]->n)
            return (0);
    }

    return (1);
}