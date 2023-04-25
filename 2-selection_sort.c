#include "sort.h"

/**
 * swap_integers - function sawp
 * @a: number
 * @b: number
 * Return: Nothing
 */
void swap_integers(int *a, int *b)
{
	int tmp = *a;

	*a = *b;
	*b = tmp;
}

/**
 * selection_sort - function selection_sort
 * @array: array
 * @size: size
 * Return: Nothing
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j;
	size_t min = 0;

	for (i = 0; i < size - 1; i++)
	{
		min = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min])
				min = j;
		}

		if (i != min)
		{
			swap_integers(&array[min], &array[i]);
			print_array(array, size);
		}
	}
}
