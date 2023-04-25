#include "sort.h"
/**
 * count- count
 *
 * @array: array
 * @size: size
 * @a: number
 *
 * Return: total
 */
int count(int *array, size_t size, int a)
{
	int total = 0;
	size_t i;

	for (i = 0; i < size; i++)
	{
		if (array[i] == a)
			total++;
	}
	return (total);
}

/**
 * counting_sort - counting sort algorithm
 *
 * @array: array to be sorted
 * @size: size of the array
 */
void counting_sort(int *array, size_t size)
{
	int k = 0, b = 0, a = 0;
	size_t i, c;
	int *array2, *newArray;

	if (!array || size < 2)
		return;
	for (i = 0; i < size; i++)
	{
		if (array[i] > k)
		{
			k = array[i];
		}
	}
	array2 = malloc(sizeof(int) * (k + 1));
	if (!array2)
		return;
	for (c = 0; c < ((size_t)k + 1); c++)
	{
		if (c == 0)
			array2[c] = count(array, size, a);
		else
		{
			b = array2[c - 1] + count(array, size, a);
			array2[c] = b;
		}
		a++;
	}
	print_array(array2, (k + 1));
	newArray = malloc(sizeof(int) * size);
	if (!newArray)
	{
		free(array2);
		return;
	}
	for (i = 0; i < size; i++)
		newArray[array2[array[i]]-- - 1] = array[i];
	for (i = 0; i < size; i++)
		array[i] = newArray[i];
	free(newArray);
	free(array2);
}
