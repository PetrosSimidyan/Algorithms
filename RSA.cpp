//////////////////////////////////////////////////////////////////
//////**************RSA Cryptosystem
//////**************Author: Petros Simidyan
////*****************

#include <iostream>
#include <ctime>
#include <cstdlib>

typedef  unsigned int  uint;

constexpr uint gCD(uint a, uint b)
{
	if (b == 0)
		return a;
	else
		return gCD(b, a%b);
}


const uint extEuclid(uint  x, uint  y, int * d, int * k)
{
	uint  sa = 1, ta = 0, sb = 0, tb = 1, q, tempA, tempB;
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
uint fastExp(int base, int exp, uint rem)
{
	while (base < 0)
		base += rem;
	//if the exponent is negative we should set the
	//modular multiplicative inverse of base to base and exp = -exp
	//e.g. we have to count 2^(-123)%3=(2^-1%3)^123%3=-1^123%3
	//because -1 is modular multiplicative inverse of 2 with 2*(-1)%3=1
	if (exp < 0)
	{
		int temp = 0;
		extEuclid(base, rem, &base, &temp);
		return fastExp(base, -1 * exp, rem);
	}
	uint res = 1;
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

const uint prepareKey(int& e, int&d)
{
	using namespace std;
	//First we have to choose two different prime numbers p and q
	uint p = 67, q = 193;
	//now we count N = p*q
	uint rem = p * q;
	//now we count euler = (p-1)(q-1)
	uint euler = (p - 1)*(q - 1);
	//after that we count the public key e,
	//with 1<e<euler and GCD(e,euler) = 1
	uint pubKey;
	do {
		pubKey = rand() % (euler - 1) + 1;
	} while (gCD(pubKey, euler) != 1);
	e = pubKey;
	//now we count private key d, with (e*d) % euler = 1,
	//using extended euclidian algorithm
	int privKey, k;
	extEuclid(pubKey, euler, &privKey, &k);
	d = privKey;
	return rem;
}

const uint encrypt(uint mes, int pub_key, uint rem)
{
	return fastExp(mes, pub_key, rem);
}

const uint decrypt(uint mes, int priv_key, uint rem)
{
	return fastExp(mes, priv_key, rem);
}


int main()
{
	srand(time(NULL));
	int pubKey = 0, privKey = pubKey, rem;
	rem = prepareKey(pubKey, privKey);
	uint mes = rand() % rem, encMes = encrypt(mes, pubKey, rem);
	std::cout << "The message is equal to: " << mes << std::endl;
	std::cout << "The message after encryption with public key is equal to: " << encMes << std::endl;
	std::cout << "The message after decryption with private key is equal to: ";
	std::cout << decrypt(encMes, privKey, rem) << std::endl;
	return 0;
}