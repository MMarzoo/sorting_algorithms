#include "sort.h"

/**
 * swap - swaps 2 int value
 * @array: the integer array to sort
 * @size: the size of the array
 * @a: address of first value
 * @b: address of second value
 *
 * Return: void
 */
void swap(int *array, size_t size, int *a, int *b)
{
	if (*a != *b)
	{
		*a = *a + *b;
		*b = *a - *b;
		*a = *a - *b;
		print_array((const int *)array, size);
	}
}

/**
 * lomuto_partition - partitions the array
 * @array: the integer array to sort
 * @size: the size of the array
 * @low: the low index of the sort range
 * @high: the high index of the sort range
 *
 * Return: size_t
 */
size_t lomuto_partition(int *array, size_t size, ssize_t low, ssize_t high)
{
	int i, j, pivot = array[high];

	for (i = j = low; j < high; j++)
		if (array[j] < pivot)
			swap(array, size, &array[j], &array[i++]);
	swap(array, size, &array[i], &array[high]);
	return (i);
}

/**
 * quicksort - quicksorts via lomute partitioning scheme
 * @array: the integer array to sort
 * @size: the size of the array
 * @low: the low index of the sort range
 * @high: the high index of the sort range
 *
 * Return: void
 */
void quicksort(int *array, size_t size, ssize_t low, ssize_t high)
{
	if (low < high)
	{
		size_t p = lomuto_partition(array, size, low, high);

		quicksort(array, size, low, p - 1);
		quicksort(array, size, p + 1, high);
	}
}

/**
 * quick_sort - call quicksort
 * @array: the integer array to sort
 * @size: the size of the array
 *
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	if (!array || !size)
		return;
	quicksort(array, size, 0, size - 1);
}
