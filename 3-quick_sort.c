#include "sort.h"

/**
 * _swap - function that swaps integers
 * @arr: array
 * @s: size of array
 * @a: integer to swap
 * @b: integer to swap
 */


void _swap(int *arr, size_t s, int a, int b)
{
	int tmp;

	if (arr[a] != arr[b])
	{
	tmp = arr[a];
	arr[a] = arr[b];
	arr[b] = tmp;
	print_array(arr, s);
	}
}

/**
 * partition - Lomuto partition scheme.
 * @arr: array
 * @s: size of array
 * @low: first element of array
 * @high: last element of array
 * Return: pivot element
 */


int partition(int *arr, size_t s, int low, int high)
{
	int pivot = arr[high];
	int i = low, j;

	for (j = low; j <= high; j++)
	{
		if (arr[j] < pivot)
		{
			_swap(arr, s, i, j);
			i++;
		}
	}
	_swap(arr, s, i, high);
	return (i);
}

/**
 * real_sort - founction that sorts array
 * using Quick sort algorithm.
 * @array: array
 * @size: size of array
 * @low: first element of array
 * @high: last element of array
 */


void real_sort(int *array, size_t size, int low, int high)
{
	int pi;

	if (low < high)
	{
		pi = partition(array, size, low, high);

		real_sort(array, size, low, pi - 1);
		real_sort(array, size, pi + 1, high);
	}
}

/**
 * quick_sort - sorts array of integers in ascending order
 * @array: array
 * @size: size of array
 */

void quick_sort(int *array, size_t size)
{
	if (!array)
		return;

	real_sort(array, size, 0, size - 1);
}

