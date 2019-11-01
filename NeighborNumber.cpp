
//////////////////////////////////////////////////////////////////
//////**************	Neighbor Numbers
//////****************Author: Petros Simidyan
////*****************

#include <iostream>

const unsigned int MAX = 5;

//dynamic array structure 
//which helps us to build the hash table
struct DynArr
{
	int *arr;
	int count, size;
	DynArr(const int& s = 5)
	{
		size = s;
		count = 0;
		arr = new int[size];
	}
	~DynArr() { delete[] arr; }
	//function checks the presence of
	//integer "input" in dyn. array
	bool  isThere(const int& input) const
	{
		for (int i = 0; i < count; i++)
			if (arr[i] == input)
				return true;
		return false;
	}
	//function for adding element
	//"input" in dynamic array
	void addEl(const int input)
	{
		if (!this->isThere(input))
		{
			if (count + 1 >= size)
			{
				int step = 5;
				int *ptr = new int[size + step];
				for (int i = 0; i < size; i++)
					ptr[i] = arr[i];
				delete[] arr;
				arr = ptr;
				size += step;
			}
			arr[count++] = input;
		}
	}
};

//recursive reminder function,
//for negative and positive numbers
inline int modulo(int left, const int& right)
{
	if (left >= 0 && left < right)
		return left;
	else
		return modulo(left < 0 ? left + right : left - right, right);
}

//making hash table (with reminder) for array arr with length len
DynArr* makeHush(const int* arr, const int len)
{
	DynArr *hushTab = new DynArr[10];
	int index = -1;
	for (int i = 0; i < len; i++)
	{
		index = modulo(arr[i], 10);
		hushTab[index].addEl(arr[i]);
	}
	return hushTab;
}
//the function finds all elements in this hash table,
//that occurs in array arr of length len, and prints it
void  checkInHush(const DynArr *hushTab, const int* arr, const int& len)
{
	int index = -1;
	for (int i = 0; i < len; i++)
	{
		index = modulo(arr[i], 10);
		if (hushTab[index].isThere(arr[i]))
			std::cout << arr[i] << ", ";
	}
	std::cout << std::endl;
}

int main()
{
	int arr1[MAX] = { 1,32,45,4,67 }, arr2[MAX] = { 1,54,32,73,4 };
	DynArr *hushTab = new DynArr[10];
	hushTab = makeHush(arr1, MAX);
	std::cout << "Here are all repeating elements of both array!" << std::endl;
	checkInHush(hushTab, arr2, MAX);
	return 0;
}