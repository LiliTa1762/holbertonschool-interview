#include "search_algos.h"
/**
 * print - helper function to print the array
 * @array: is a pointer to the first element of the array to print
 * @left_value: first element of the array
 * @right_value: last element of the array
 * Return: Nothing
 **/
void print(int *array, size_t left_value, size_t right_value)
{
	printf("Searching in array: ");
	while (left_value < right_value)
	{
		printf("%i, ", array[left_value]);
		left_value++;
	}
	printf("%i\n", array[left_value]);
}
/**
 * use_recursion - helper function to search
 * @array: is a pointer to the first element of the array to search in
 * @left_value: index of first element of the array
 * @right_value: index of last element of the array
 * @value: is the value to search for
 * Return: the index where value is located, otherwise return -1
 **/
int use_recursion(int *array, int left_value, int right_value, int value)
{
	int middle;

	print(array, left_value, right_value);
	middle = (right_value - left_value) / 2 + left_value;
	if (left_value == right_value)
		return (-1);
	if (array[middle] == value && array[middle - 1] != value)
		return (middle);
	if (array[middle] >= value)
		return (use_recursion(array, left_value, middle, value));
	if (array[middle] <= value)
		return (use_recursion(array, middle + 1, right_value, value));
	return (-1);
}
/**
 * advanced_binary - searches a value in a sorted array of int
 * @array: pointer to the first element of the array to search in
 * @size: is the number of elements in array
 * @value: is the value to search for
 * Return: the index where value is located, otherwise return -1
 **/
int advanced_binary(int *array, size_t size, int value)
{
	if (array == NULL)
		return (-1);
	return (use_recursion(array, 0, size - 1, value));
}
