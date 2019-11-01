
#include <iostream>
#include <climits>
#include <random>
#include <ctime>

//number length of array
const unsigned int  numOfElements = 20;
//maximal value of elements in array
const unsigned int maxValue = 100;

//inline function for swaping two elements of an array
inline void swap(int *arr, int i, int j)
{
	int temp = *(arr + i);
	*(arr + i) = *(arr + j);
	*(arr + j) = temp;
}

//inline function for filling an array of length max with random integers
inline void createVec(int *arr, int max = numOfElements)
{
	srand(time(NULL));
	for (int i = 0; i < max; i++)
		*(arr + i) = rand() % maxValue;
}

//printing integer array of length length
inline void printArr(int *arr, int length=numOfElements)
{
	for (int i = 0; i < length; i++)
		std::cout << *(arr + i) << ", ";
	std::cout << std::endl;
}

//function for finding the minimal element of an int-array
//of length length, startig with position i
int findMin(int *arr, int i, int length)
{
	int min = INT_MAX, index = -1;
	for (; i < length; i++)
		if (*(arr + i) < min)
		{
			min = *(arr + i);
			index = i;
		}
	return index;
}

void selectionSort(int *arr, int length)
{
	int minIndex = -1;
	printArr(arr, length);
	for (int i = 0; i < length - 1; i++)
	{
		minIndex = findMin(arr, i, length);
		if (minIndex != i)
			swap(arr, i, minIndex);
		printArr(arr, length);
	}
}


int main()
{
	int arr[numOfElements];
	createVec(arr);
	selectionSort(arr, numOfElements);
	return 0;
}
