//////////////////////////////////////////////////////////////
//****************	PRIME FACTORIZATION		*********************
//****************Author: Petros Simidyan**********************
///////////////////////////////////////////////////////////////

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;


//returns true, if input is a prime 
bool isPrime(const int input)
{
	bool output = true;
	for (int i = 2; i*i <= input; i++)
		if (input%i == 0)
		{
			output = false;
			break;
		}
	return output;
}

//returns vector of prime values 
//needed for factorization
vector<int> vecOfPrimes(const int input)
{
	vector<int> output;
	for (int i = 2; i <= input / 2; i++)
		if (isPrime(i))
			output.push_back(i);
	return output;
}

string printSolution(vector<int> primeVec, int input)
{
	string output = to_string(input) + " = ";
	if (isPrime(input))
		return to_string(input) + " is prime!\nPrime factorization is inpossible!";
	else
	{
		while (input > 1)
		{
			for (int i = 0; i < primeVec.size(); i++)
				if (input%primeVec[i] == 0)
				{
					input /= primeVec[i];
					output += to_string(primeVec[i]) + "*";
					break;
				}
		}
	}
	return output.substr(0, output.size() - 1);
}


int main()
{
	int input;
	while (true)
	{
		cout << "Please give an positiv integer number greater or equal 2!" << endl;
		//making sure, that the input positiv 
		if (cin.peek() == '-') {
			cout << "The given integers should be positiv!" << endl;
			cin.clear();
			cin.ignore(10000, '\n');
		}
		else {
			cin >> input;
			//checks, that the input is an integer
			if (cin.fail()) {
				cout << "The input is not an unsigned integer!" << endl;
				cin.clear();
				cin.ignore(10000, '\n');
			}
			else
			{
				vector<int> primeVec = vecOfPrimes(input);
				//returns the list of prime factorisations
				for (int i = 2; i <= input; i++)
					cout << printSolution(primeVec, i) << endl;
			}
		}
	}
	return 0;
}