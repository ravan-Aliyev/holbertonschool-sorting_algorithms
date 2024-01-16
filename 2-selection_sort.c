#include "sort.h"
/**
 * selection_sort - sorting array with selection algoritm.
 * @array: array of intiger.
 * @size: size of array.
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j;
	int min, tmp;

	for (i = 0; i < size - 1; i++)
	{
		min = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min])
				min = j;
		}
		if (min != (int)i)
		{
			tmp = array[i];
			array[i] = array[min];
			array[min] = tmp;
			print_array(array, size);
		}
	}
}
