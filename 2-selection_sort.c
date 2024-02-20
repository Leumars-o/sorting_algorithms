#include "sort.h"
#include <stdio.h>
/**
 * selection_sort - a function that sorts an array using selection sort
 * @array: given array to be sorted
 * @size: size of the array to be sorted
 * Return: Void
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j;
	int least = 0, count = 0;

	if (array == NULL || size == 0)
		return;
	for (i = 0; i < size; i++)
	{
		least = array[i];
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < least)
			{
				least = array[j];
				count = j;
			}
		}
		if (least != array[i])
		{
			array[count] = array[i];
			array[i] = least;
		}
		print_array(array, size);
	}
}

