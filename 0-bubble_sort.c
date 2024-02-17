#include "sort.h"
/**
 * bubble_sort - function that sorts an array of ints
 * using bubble sort algorithm
 *
 *@array: array of ints
 *@size: size of arrayy
 *
 */
void bubble_sort(int *array, size_t size)
{
	int tmp;
	size_t a, b;

	if (!array || !size)
		return;

	a = 0;
	while (a < size)
	{
		for (b = 0; b < size; b++)
		{
			if (array[b] > array[b + 1])
			{
				tmp = array[b];
				array[b] = array[b + 1];
				array[b + 1] = tmp;
				print_array(array, size);
			}
		}
		a++;
	}
}
