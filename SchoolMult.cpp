//////////////////////////////////////////////////////////////////
//////************** Multiply two numbers like on paper
//////****************Author: Petros Simidyan******
////*****************
////
#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>

using namespace std;

#define CLEAR cin.clear(); cin.ignore(1000, '\n');
#define MAX(a,b) ((a)>(b)?(a):(b))

typedef unsigned long long ulong;
//the function returns the length of a given integer
inline ulong intLength(ulong input)
{
	ulong count = 0;
	while (input > 0)
	{
		count++;
		input /= 10;
	}
	return count;
}
//the function returns the maximal length of given  2 integers
inline ulong maxLength(ulong i1, ulong i2)
{
	return MAX(intLength(i1), intLength(i2));
}
//function prints line of length of goven integer
inline void printLine(const ulong input)
{
	string line(intLength(input), '-');
	cout << setw(20) << line << endl;
}
//the main function
ulong printSolution(const ulong i1, ulong i2)
{
	int zeros = 0;
	ulong mult, result = 0;
	while (i2 > 0)
	{
		mult = i1 * (i2 % 10);
		if (mult != 0)
		{
			mult *= pow(10, zeros);
			cout << setw(20) << mult << endl;
			result += mult;
		}
		i2 /= 10;
		zeros++;
	}
	return result;
}
int main()
{
	ulong i1, i2, solution;

	while (true)
	{
		cout << "Please give 2 positiv integers number:" << endl;
		//making sure, that the input is positiv 
		if (cin.peek() == '-') {
			cout << "The given integers should be positiv!" << endl;
			CLEAR
		}
		else {
			cin >> i1;
			cin >> i2;
			//checking, that the input is an integer
			if (cin.fail()) {
				cout << "Wrong input!" << endl;
				cout << "Your input is not an integer!" << endl;
				CLEAR
			}
			else
			{
				cout << "Here is the solution for yout input: " << endl;
				cout << setw(20) << i1 << endl;
				cout << setw(20 - intLength(i1)) << "x" << endl;
				cout << setw(20) << i2 << endl;
				printLine(MAX(i1, i2));
				solution = printSolution(i1, i2);
				printLine(solution);
				cout << setw(20) << solution << endl;
			}
		}
	}
	return 0;
}