
//////////////////////////////////////////////////////////////////
//////**************	Palindromic Number
//////****************Author: Petros Simidyan
////*****************

#include <iostream>

//recursive function, that returns the number of digits the given integer
constexpr int numberOfDigits(const int& input, const int& number = 0)
{
	if (input < 10)
		return number + 1;
	return numberOfDigits(input / 10, number + 1);
}
//help funtion: returns 10^pow
constexpr int power(const int& pow, const int& base = 10, const int& output = 1)
{
	if (pow < 1)
		return output;
	return power(pow - 1, base, output*base);
}
//function returns true if the given number is palindrom
constexpr bool isPalindromNumber(const int& input)
{
	if (input < 10)
		return true;
	int pow = numberOfDigits(input);
	int firstDigit = input / power(pow - 1);
	int lastDigit = input % 10;
	if (firstDigit != lastDigit)
		return false;
	else
		return isPalindromNumber((input%power(pow - 1)) / 10);
}

inline void printAllPalindrom(const int& max)
{
	std::cout << "Here are all palindrom numbers between 11 and " << max << std::endl;
	for (int i = 11; i <= max; i++)
		if (isPalindromNumber(i))
			std::cout << i << ", ";
	std::cout << std::endl;
}

int main()
{
	printAllPalindrom(100000);
	return 0;
}