////////////////////////////////////////////////////////////////////
////////**************CHALLENGE:Kaprekar's Numbers
////////****************Author: Petros Simidyan
//////*****************
/*The idea is folowing:
save in array of length 10 number occurrence
of each digit in input integer. After that we
use this array to arrange the digits in des und aus way.
Example:
Input: 4466
Counterarray:
indices:0123456789
values: 0000202000

Input: 4567
Counterarray:
indices:0123456789
values: 0000111100

Input: 2333
Counterarray:
indices:0123456789
values: 0013000000

For arranging the given digit in des oreder
we  need to go throw the array starting with
the last element, in other case with 0 index.
*/

#include <iostream>
#include <vector>

#define MAX 10
#define CLEAR std::cin.clear(); std::cin.ignore(1000, '\n');
#define KAR 6174

//the function counts the number of digits of the given integer
//for testing, that the given integer has only 4 digits
inline int numOfDigit(const int& input, const int& digits = 0)
{
	if (input == 0)
		return digits;
	return numOfDigit(input / 10, digits + 1);
}

//the function test the input has only one digit, e. g. 4444, 1111
inline bool contSameNum(const int& input, const int& lastDigit)
{
	if (input < 10)
		return input == lastDigit;
	if (input % 10 == lastDigit)
		return contSameNum(input / 10, input % 10);
	return false;
}

inline bool contSameNum(const int& input)
{
	return contSameNum(input, input % 10);
}

//initialising  all elements of the
//given array input of length len with 0
inline void initIntArr(int* input, const int& len = MAX)
{
	for (int i = 0; i < MAX; i++)
		input[i] = 0;
}

//"mixes" the greatest value
inline int mixMax(int* countArr)
{
	int max = 0, i = MAX - 1, count = -1;;
	for (; i >= 0; i--)
		if (countArr[i] > 0)
		{
			count = countArr[i];
			while (count-- > 0)
				max = 10 * max + i;
		}
	return max;
}

inline int mixMin(int* countArr)
{
	int min = 0, i = 0, count = -1;
	for (; i < MAX; i++)
		if (countArr[i] > 0)
		{
			count = countArr[i];
			while (count-- > 0)
				min = 10 * min + i;
		}
	return min;
}

//the function creates a counter array, 
//and initialises input, mixMax and mixMin
inline void initMinMax(int& input, int& max, int& min)
{
	int * countArr = new int[MAX];
	initIntArr(countArr);
	int lastDigit = -1;
	while (input > 0)
	{
		lastDigit = input % 10;
		countArr[lastDigit]++;
		input /= 10;
	}
	max = mixMax(countArr);
	min = mixMin(countArr);
	input = max - min;
	delete[]countArr;
}

inline void printStep(const int& input, const int& max, const int& min)
{
	std::cout << max << " - " << min << " = " << input << std::endl;
}

inline int printKaprekar(int input)
{
	int max = 0, min = 0, steps = 7;
	while (steps-- > 0 && input != KAR)
	{
		initMinMax(input, max, min);
		printStep(input, max, min);
	}
	return input;
}
int main()
{
	int input = -1;
	while (true)
	{
		std::cout << "Please give an positiv four-digits integer number!" << std::endl;

		if (std::cin.peek() == '-') {//making sure, that ght input an positiv integer is
			std::cout << "The given integers should be positiv!" << std::endl;
			CLEAR
		}
		else {
			std::cin >> input;
			if (std::cin.fail() || numOfDigit(input) != 4 || contSameNum(input)) {
				std::cout << "Wrong input!" << std::endl;
				std::cout << "Try again!" << std::endl;
				CLEAR
			}
			else
			{
				std::cout << "Here is step by step computation for your input:" << std::endl;
				int testVal = printKaprekar(input);
				std::cout << "Your input is" << ((testVal == KAR) ? " " : " not ") << "a Kaprekar number" << std::endl;
			}

		}
	}
	return 0;
}