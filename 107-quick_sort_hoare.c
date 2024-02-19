#include "sort.h"
#include <stdio.h>
/**
 * swap - change two values in ascending or descending order
 * @array: array
 * @a: item one
 * @b: item two
 * @order: 1: ascending order, 0 descending order
 */
void swap(int array[], int a, int b, int order)
{
	int tmp;

	if (order == (array[a] > array[b]))
	{
		tmp = array[a];
		array[a] = array[b];
		array[b] = tmp;
	}
}

/**
 * merge - sort bitonic sequences recursively in both orders
 * @array: array
 * @low: first element
 * @n: elements number
 * @order: 1: ascending order, 0 descending order
 */
void merge(int array[], int low, int n, int order)
{
	int mid, i;

	if (n > 1)
	{
		mid = n / 2;
		for (i = low; i < low + mid; i++)
			swap(array, i, i + mid, order);
		merge(array, low, mid, oder);
		merge(array, low + mid, mid, order);
	}
}

/**
 * bitonicsort - bitonic sort algorithm implementation
 * @array: array
 * @low: first element
 * @n: number of elements
 * @order: 1: ascending order, 0 descending order
 * @size: array lenght
 */
void bitonicsort(int array[], int low, int n, int order, int size)
{
	int mid;
	
	if (n > 1)
	{
		if (order >= 1)
		{
			printf("Merging [%i/%i] (UP):\n", n, size);
			print_array(&array[low], n);
		}
		else
		{
			printf("Merging [%i/%i] (DOWN):\n", n, size);
			print_array(&array[low], n);
		}
		mid = n / 2;
		bitonicsort(array, low, mid, 1, size);
		bitonicsort(array, low + mid, mid, 0, size);
		merge(array, low, n, order);
		if (order <= 0)
		{
			printf("Result [%i/%i] (DOWN):\n", n, size);
			print_array(&array[low], n);
		}
		if (order >= 1)
		{
			printf("Result [%i/%i] (UP):\n", n, size);
			print_array(&array[low], n);
		}
	}
}

/**
 * bitonic_sort - prepare the terrain to bitonic sort algorithm
 * @array: array
 * @size: array lenght
 */
void bitonic_sort(int *array, size_t size)
{
	int order = 1;
	if (!array || size < 2)
		return;
	bitonicsort(array, 0, size, order, size);
}
