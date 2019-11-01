//////////////////////////////////////////////////////////////////
//////**************	 Decimal to Rational
//////****************Author: Petros Simidyan
////*****************

#include <iostream>

constexpr int gCD(const int& a, const int& b)
{
	if (b == 0)
		return a;
	else
		return gCD(b, a%b);
}

inline void toNeg(const bool& isNeg, int& input)
{
	if (isNeg) { input = -input; }
}

inline void printFraction(const double& input)
{
	int denom = 10000;
	int numer = input * denom;
	bool isNeg = input < 0;
	toNeg(isNeg, numer);
	int gcd = gCD(denom, numer);
	denom /= gcd;
	numer /= gcd;
	toNeg(isNeg, numer);
	std::cout << input << " = " << numer;
	if (denom != 1)
		std::cout << '/' << denom;
	std::cout << std::endl;
}

int main()
{
	printFraction(123.456);
	printFraction(0.456);
	printFraction(-1.456);
	printFraction(12);
	return 0;
}