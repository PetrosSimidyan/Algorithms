//////////////////////////////////////////////////////////////////
//////**************Pseudorandom number generator
//////**************using RSA cryptosystem
//////**************Author: Petros Simidyan
////*****************


#include <iostream>
#include <ctime>
#include <cstdlib>

typedef  unsigned long long  ulong;
const short maxBits = 64;

inline ulong gCD(ulong a, ulong b)
{
	if (b == 0)
		return a;
	else
		return gCD(b, a%b);
}


const ulong extEuclid(ulong  x, ulong  y, int * d, int * k)
{
	ulong  sa = 1, ta = 0, sb = 0, tb = 1, q, tempA, tempB;
	int  a = x, b = y;
	while (b > 0)
	{
		q = a / b;
		tempA = a; a = b; b = tempA - q * b;
		tempA = sa; tempB = ta; sa = sb; ta = tb;
		sb = tempA - q * sb; tb = tempB - q * tb;
	}
	*d = sa; *k = ta;
	return a;
}

//function counts (base^exp)%rem in O(ld(n)) time
ulong fastExp(int base, ulong exp, ulong rem)
{
	while (base < 0)
		base += rem;
	ulong res = 1;
	base = base % rem;
	while (exp > 0)
	{
		if (exp & 1)
			res = (res*base) % rem;
		exp = exp >> 1;
		base = (base*base) % rem;
	}
	return res;
}

inline  const ulong prepareKey(ulong& key)
{
	//First we have to choose two different prime numbers p and q
	ulong p = 67, q = 193;
	//now we count N = p*q
	ulong rem = p * q;
	//now we count euler = (p-1)(q-1)
	ulong euler = (p - 1)*(q - 1);
	//after that we count the public key e,
	//with 1<e<euler and GCD(e,euler) = 1
	ulong pubKey = 0;
	do {
		pubKey = rand() % (euler - 1) + 1;
	} while (gCD(pubKey, euler) != 1);
	key = pubKey;
	return rem;
}

inline const ulong PRBG(ulong key, ulong rem)
{
	//creating random value<2^16
	int temp = rand();
	ulong randVal = 0;
	for (short i = 0; i < maxBits; i++)
	{
		//encrypting this value with RSA
		temp = fastExp(temp, key, rem);
		//seting i-th bit of the big random value 'randVal'
		//with the least significant bit of 'temp' 
		randVal |= ((ulong)(temp & 1) << i);
	}
	//returning Pseudo Random number of length maxBits 
	return randVal;
}

inline const ulong randVal()
{
	ulong key = 0, rem = prepareKey(key);
	return PRBG(key, rem);
}

int main()
{
	srand(time(NULL));
	std::cout << randVal() << std::endl;
	std::cout << randVal() << std::endl;
	std::cout << randVal() << std::endl;
	std::cout << randVal() << std::endl;
	std::cout << randVal() << std::endl;
	return 0;
}