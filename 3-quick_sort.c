#include "sort.h"

/**
 * quick_sort - a function that sorts an array using the quick sort algo
 * @array: given array to sort
 * @size: size of the array
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	q_sort(array, 0, size - 1, size);
}

/**
 * partition - a function that splits an array
 * @array: array
 * @lesser: lower
 * @greater: higher
 * @size: array's size
 * Return: i
 */
int partition(int *array, int lesser, int greater, size_t size)
{
	int i = lesser - 1, j = lesser;
	int pivot = array[greater], aux = 0;

	for (; j < greater; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (array[i] != array[j])
			{
				aux = array[i];
				array[i] = array[j];
				array[j] = aux;
				print_array(array, size);
			}
		}
	}
	if (array[i + 1] != array[greater])
	{
		aux = array[i + 1];
		array[i + 1] = array[greater];
		array[greater] = aux;
		print_array(array, size);
	}
	return (i + 1);
}

/**
 * q_sort - quick sort
 * @array: given array
 * @lesser: lower
 * @greater:higher
 * @size: array's size
 * Return: void
 */
void q_sort(int *array, int lesser, int greater, size_t size)
{
	int pivot;

	if (lesser < greater)
	{
		pivot = partition(array, lesser, greater, size);
		q_sort(array, lesser, pivot - 1, size);
		q_sort(array, pivot + 1, greater, size);
	}
}
