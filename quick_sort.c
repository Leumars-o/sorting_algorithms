#include "sort.h"
#include <stdio.h>

int *split_array(int *array, size_t start, size_t end);

int *join(int *array1, int arr1_size, int *array2, int arr2_size, int pivot);

void swap(int *item1, int *item2);

int array_size(int *array);

/**
* quick_sort - a function that sorts an array using quick sort algo
* @array: Array to be sorted
* @size: the size of the array to be sorted
* Return: void
*/
void quick_sort(int *array, size_t size)
{
	size_t pivot = 0, comp = size - 1;
	int *greater, *lesser, *sorted, tmp, greater_size = 0, lesser_size = 0;

	while (pivot != comp)
	{
		if (pivot < comp && (array[pivot] > array[comp]))
		{
			swap(&array[pivot], &array[comp]);
			tmp = pivot;
			pivot = comp;
			comp = tmp;
		}
		else if (pivot > comp && (array[pivot] < array[comp]))
		{
			swap(&array[pivot], &array[comp]);

			tmp = pivot;
			pivot = comp;
			comp = tmp;

		}

		if (pivot < comp)
			comp--;
		else
			comp++;
	}
	/*split the array to two parts*/
	greater = split_array(array, pivot + 1, size - 1);
	lesser = split_array(array, 0, pivot - 1);

	/*Join the greater, lesser and pivot arrays*/
	greater_size = size - pivot - 1;
	lesser_size = pivot;
	sorted = join(greater, greater_size, lesser, lesser_size, pivot);
	print_array(sorted, size);
}
/**
* split_array - a function that splits an array
* @array: the array to be split
* @start: the start point to split from
* @end: the stop point of the split
* Return: Void
*/
int *split_array(int *array, size_t start, size_t end)
{
	size_t array_size, i;
	int *new_array;

	array_size = end - start + 1;
	new_array = malloc(array_size * sizeof(int));
		if (new_array == NULL)
			return (0);
	for (i = start; i <= end; i++)
	{
		new_array[i - start] = array[i];
	}
	return (new_array);
}
/**
* swap - function that swaps 2 items
* @item1: first item to be swapped
* @item2: second item to be swapped
* Return: void
*/
void swap(int *item1, int *item2)
{
	int tmp;

	tmp = *item1;
	*item1 = *item2;
	*item2 = tmp;
}
/**
* join - a function that joins 2 arrays and an int
* @array1: the first array to join
* @arr1_size: size of the first array
* @array2: the 2nd array to join
* @arr2_size: size of the 2nd array
* @pivot: the int to be joined
* Return: new array of ints
*/
int *join(int *array1, int arr1_size, int *array2, int arr2_size, int pivot)
{
	int *new_array, i;

	new_array = malloc((arr1_size + arr2_size + 1) * sizeof(int));
	if (new_array == NULL)
		return (0);
	for (i = 0; i < arr1_size; i++)
	{
		new_array[i] = array1[i];
	}

	new_array[arr1_size] = pivot;

	for (i = 0; i < arr2_size; i++)
	{
		new_array[i + arr2_size] = array2[i];
	}
	return (new_array);
}
