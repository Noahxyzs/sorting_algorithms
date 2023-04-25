#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * copy - copy
 *
 * @src: src
 * @dst: dst
 * @size: size
 *
 * Return: Nothing
 */
void copy(int *src, int *dst, int size)
{
	int i;

	for (i = 0; i < size; i++)
		dst[i] = src[i];
}
/**
 * merge - merges
 *
 * @array: array
 * @buff: buff
 * @minL: minl
 * @maxL: maxl
 * @minR: minr
 * @maxR: maxr
 *
 * Return: Nothing
 */
void merge(int *array, int *buff, int minL, int maxL, int minR, int maxR)
{
	int i = minL, j = minR, k = minL;

	while (i <= maxL || j <= maxR)

		if (i <= maxL && j <= maxR)
			if (buff[i] <= buff[j])
				array[k] = buff[i], k++, i++;
			else
				array[k] = buff[j], k++, j++;

		else if (i > maxL && j <= maxR)
			array[k] = buff[j], k++, j++;
		else
			array[k] = buff[i], k++, i++;
}
/**
 * printcheck - printcheck
 *
 * @array: array
 * @r1: int
 * @r2: int
 *
 * Return: Nothing
 */
void printcheck(int *array, int r1, int r2)
{
	int i;

	for (i = r1; i <= r2; i++)
	{
		if (i > r1)
			printf(", ");
		printf("%d", array[i]);
	}
	printf("\n");
}
/**
 * split - split
 *
 * @array: array
 * @buff: buff
 * @min: min
 * @max: max
 * @size: size
 *
 * Return: Nothing
 */
void split(int *array, int *buff, int min, int max, int size)
{
	int mid, tmax, minL, maxL, minR, maxR;

	if ((max - min) <= 0)
		return;

	mid = (max + min + 1) / 2;
	tmax = max;
	max = mid - 1;

	minL = min;
	maxL = max;

	split(array, buff, min, max, size);

	min = mid;
	max = tmax;

	minR = min;
	maxR = max;

	split(array, buff, min, max, size);

	printf("Merging...\n");
	printf("[left]: ");

	printcheck(array, minL, maxL);

	printf("[right]: ");

	printcheck(array, minR, maxR);
	merge(array, buff, minL, maxL, minR, maxR);
	copy(array, buff, size);

	printf("[Done]: ");
	printcheck(array, minL, maxR);
}
/**
 * merge_sort - merge_sort
 *
 * @array: array
 * @size: size
 *
 * Return: Nothing
 */
void merge_sort(int *array, size_t size)
{
	int *buff;

	if (size < 2)
		return;

	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;

	copy(array, buff, size);

	split(array, buff, 0, size - 1, size);

	free(buff);
}
