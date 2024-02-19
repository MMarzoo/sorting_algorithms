#include "sort.h"
#include <stdio.h>
/**
* getMax - A utility function to get maximum value in arr[]
* @array: array
* @n: size of the array
* Return: array
*/
int getMax(int *array, int n)
{
	int i, max = array[0];

	for (i = 1; i < n; i++)
	{
		if (array[i] > max)
		{
			max = array[i];
		}
	}
	return (max);
}

/**
* countSort - A function to do counting sort of arr[] according to
* the digit represented by exp.
* @array: array
* @n: size of the array
* @exp: exp is 10^i
* @output: array to save the temporary values
*/
void countSort(int *array, size_t n, int exp, int *output)
{
	int i = 0;
	int count[10] = {0};

	for (i = 0; i < (int)n; i++)
		count[(array[i] / exp) % 10]++;

	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (i = n - 1; i >= 0; i--)
	{
		output[count[(array[i] / exp) % 10] - 1] = array[i];
		count[(array[i] / exp) % 10]--;
	}
	for (i = 0; i < (int)n; i++)
		array[i] = output[i];
}

/**
* radix_sort - The main function to that sorts arr[]
* of size n using Radix Sort
* @array: array
* @size: size of the array
*/
void radix_sort(int *array, size_t size)
{
	int exp, max = 0;
	int *output = 0;

	if (!array || size < 2)
		return;

	max = getMax(array, size);
	output = malloc(size * sizeof(int));
	if (!output)
		return;
	for (exp = 1; max / exp > 0; exp *= 10)
	{
		countSort(array, size, exp, output);
		print_array(array, size);
	}
	free(output);
}
