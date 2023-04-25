#ifndef SORT_H_
#define SORT_H_

#include <stdio.h>
#include <stdlib.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: node
 * @prev: prev
 * @next: next
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void swap_nodes(listint_t **list, listint_t **node1, listint_t **node2);
void selection_sort(int *array, size_t size);
void swap_integers(int *a, int *b);
void quick_sort(int *array, size_t size);
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
listint_t *create_listint(const int *array, size_t size);

#endif
