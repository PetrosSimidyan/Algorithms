////////////////////////////////////////////////////////////////
////**************Prime number generator using Miller-Rabin test 
////************** version 2.0 (generating 32 bit prime values)
////****************Author: Petros Simidyan
//*****************

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>

typedef  unsigned long long ulong;
//error posibility by 1/4^maxLoop
const int maxLoop = 1000000;

//the function returns true,
//if the given number n is odd
inline const bool isOdd(ulong n)
{
	return (n & 1);
}

//creats random value<2^32	
ulong bigRandVal()
{
	//rand() creates random values<2^16,
	 //to create values <2^32, function
	 //need to shift left 2 bytes
	ulong output = rand();
	output <<= 16;
	output ^= rand();
	return output;
}
//help function for Miller-Rabin test
//brings the given number in form OddFactor*2^exp
//e.g. 84 = 21*2^2, with exp = 2, OddFactor=21
inline const ulong findOddFact(ulong input, ulong &exp)
{
	exp = 0;
	while (!isOdd(input))
	{
		++exp;
		input = input >> 1;
	}
	return input;
}

//function counts (base^exp)%rem in O(ld(n)) time
ulong fastExp(ulong base, ulong exp, ulong rem)
{
	ulong res = 1;
	base = base % rem;
	while (exp > 0)
	{
		if (isOdd(exp))
			res = (res*base) % rem;
		exp = exp >> 1;
		base = (base*base) % rem;
	}
	return res;
}

const bool MiRaTest(ulong input)
{
	ulong exp = 0, a = (rand() % (input - 1)) + 1;
	ulong oddFac = findOddFact(input - 1, exp);
	ulong b = fastExp(a, oddFac, input);
	if (b == 1 || b == input - 1) return true;
	for (int i = 1; i < exp; i++)
	{
		b = b * b%input;
		if (b == input - 1)return true;
		if (b == 1)return false;
	}
	return false;
}

//function tests the given odd number input>=5 
//with error possibility by 1/4^maxLoop
const bool MiRaLTimes(ulong input)
{
	if (!isOdd(input))return false;
	for (int i = 0; i < maxLoop; i++)
		if (!MiRaTest(input))return false;
	return true;
}

//	function returns a prime number
//between RAND_MAX/2 and RAND_MAX
const ulong primeCreator()
{
	ulong prime;
	while (true)
	{
		prime = bigRandVal();
		if (MiRaLTimes(prime))
			return prime;
	}
}

int main()
{
	srand(time(NULL));
	std::cout << primeCreator() << std::endl;
	std::cout << primeCreator() << std::endl;
	std::cout << primeCreator() << std::endl;
	std::cout << primeCreator() << std::endl;
	return 0;
}