//////////////////////////////////////////////////////////////////
//////************** Twin Prime Numbers using own defined dymanic array
//////****************Author: Petros Simidyan
////*****************

#include <iostream>


struct DynArr
{
	int* arr;
	int count, size;

	DynArr(const int& s = 5)
	{
		size = s;
		arr = new int[size];
		count = 0;
	}
	void addEl(const int& input)
	{
		if ((count + 1) > size)
		{
			size += 5;
			int* ptr = new int[size];
			for (int i = 0; i < count; i++)
				ptr[i] = arr[i];
			delete[] arr;
			arr = ptr;
		}
		arr[count++] = input;
	}
	int operator[](const int& index) const
	{
		if (index < 0 || index >= count)
		{
			std::cerr << "Index out of range!" << std::endl;
			exit(1);
		}
		return arr[index];
	}

};

DynArr allPrimes(const int& input)
{
	DynArr primVec;
	primVec.addEl(2);
	primVec.addEl(3);
	for (int i = 4; i <= input; i++)
		for (int j = 0; j < primVec.count; j++)
		{
			if (primVec[j] * primVec[j] > i)
			{
				primVec.addEl(i);
				break;
			}
			if (i%primVec[j] == 0)
				break;
		}
	return primVec;
}

void printSolution(const int& input)
{
	if (input <= 4)
		std::cout << "There are no twin prime numbers in given ragne!" << std::endl;
	else
	{
		DynArr primVec = allPrimes(input);
		std::cout << "Here are all twin prime numbers between 4 and " << input << std::endl;
		for (int i = 0; i < primVec.count - 1; i++)
			if (primVec[i] == primVec[i + 1] - 2)
				std::cout << '(' << primVec[i] << ','
				<< primVec[i + 1] << ')' << std::endl;
	}
}


int main()
{
	printSolution(111123);
	return 0;
}

