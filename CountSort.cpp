//counting sort algorithm with explanation
//https://de.wikipedia.org/wiki/Countingsort

#include <cstdio>
#include <random>
#include <ctime>

typedef unsigned int uint;
const uint maxNum = 10;
const uint arrLen = 20;
uint countArr[maxNum];
uint intArr[arrLen];

//need the function for finding the width
//of the output depending on the maxNum
inline const uint& numberOfDigits(uint input)
{
	uint sum = 0;
	while (input > 0)
	{
		sum++;
		input /= 10;
	}
	return sum;
}

//the width value itself
const uint width = numberOfDigits(maxNum) + 1;

//the function initialises intArray with
//random values between 0 and maxNum
inline void randInit()
{
	for (int i = 0; i < arrLen; i++)
		intArr[i] = rand() % maxNum;
}

inline void printArr(const uint* arr, const uint& len)
{
	for (int i = 0; i < len; i++)
		printf("%*d,", width, arr[i]);
	printf("\n");
}

void countSort()
{
	int i = 0, j = 0;
	randInit();
	printf("The unsorted array with random values looks like this: \n");
	printArr(intArr, arrLen);
	for (; i < maxNum; i++)
		countArr[i] = 0;
	//counting the number of occurrence of each value
	//e.g. 3 occours 2 times, hence countArr[3] is equal to 2
	for (i = 0; i < arrLen; i++)
		++countArr[intArr[i]];
	printf("Counting array looks like this after the sorting: \n");
	printf("(1st row: the numbers, 2nd row: number of occouring of each value)\n");
	for (i = 0; i < maxNum; i++)
		printf("%*d,", width, i);
	printf("\n");
	printArr(countArr, maxNum);
	//sorting the input array depends on countArr
	for (i = 0; i < maxNum; i++)
		while (countArr[i])
		{
			intArr[j++] = i;
			--countArr[i];
		}
	printf("Input array looks like this after the sorting \n");
	printArr(intArr, arrLen);
}


int main()
{
	srand(time(NULL));//need this for real random values
	countSort();
	return 0;
}

