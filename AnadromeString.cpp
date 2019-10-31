//////////////////////////////////////////////////////////////////////
//////////**************CHALLENGE:Anadrome string (with user input)
//////////****************Author: Petros Simidyan
////////*****************
//Idea: if the all letter of a given string occour even times, 
// or only one letter occours odd times, then the input string is 
//anadrome. For example: aann is anadrome (only "even occouring"),
//"zanna" is anadrome too, because only one letter (in this case 'z')
// occours odd times, but "zeanna" is not a anadrome string
//(as well 'z' as 'e'occours odd times). So we need to test that

#include <iostream>

const int alphSize = 26;
const int max = 256;

//3 inline function to "prepare" the give string
//the functions help to read only letters ffrom input
//string and convert it in upper case
inline const bool& isLetter(const char& c)
{
	return (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z');
}

inline const bool& isLow(const char& c)
{
	return (c >= 'a' && c <= 'z');
}

inline const char& toUp(const char& c)
{
	if (isLow(c))
		return (c - 'a' + 'A');
	else
		return c;
}

//function returns the number of the letter in alphabet (e.g. A=0, D=3)
inline const int& indOf(const char& c)
{
	return (int)(c - 'A');
}

inline const bool& isOdd(const int& i)
{
	return i & 1;
}

//the recursive function returns "true", if 
//one of the letters in given string 
//occours odd times
const bool& isAnad(const short* alpha, const int& i = 0, const bool& oneIsOdd = 0)
{
	if (i == alphSize)
		return true;
	if (isOdd(alpha[i]))
		if (oneIsOdd)
			return false;
		else
			return isAnad(alpha, i + 1, true);
	else
		return isAnad(alpha, i + 1, oneIsOdd);
}

int main()
{
	char input[max], output[max];
	//an array of the short value which 
	//saves the number of occourance 
	//of each letter of the input string
	short alpha[alphSize];
	while (true)
	{
		std::cout << "Give the string to test!" << std::endl;
		std::cin.getline(input, max);
		for (int i = 0; i < alphSize; i++)
			alpha[i] = 0;
		int i = -1, j = 0;
		while (input[++i] != '\0')
		{
			if (isLetter(input[i]))
			{
				output[j] = toUp(input[i]);
				++alpha[indOf(output[j++])];
			}
		}
		output[j] = '\0';
		std::cout << "The given string is ";
		if (!isAnad(alpha)) std::cout << "not ";
		std::cout << "anadrome!" << std::endl;
		std::cin.clear();
	}
	return 0;
}