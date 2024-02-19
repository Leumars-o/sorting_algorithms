#include "sort.h"
#include <stdio.h>
#include <stddef.h>
/**
  * bubble_sort - a function that sorts an array of integers in ascending
  * order using the Bubble sort algorithm
  *
  * @array: given array to be sorted
  * @size: size of array to be sorted
  *
  * Return: void
  */

void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int tmp;

	if !(array && size)
		return;

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < (size - i - 1); j++)
		{
			if (array[j] > array[j + 1])
			{
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
				print_array(array, size);
			}
		}
	}
}
