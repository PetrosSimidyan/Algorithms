////////////////////////////////////////////////////////////////
//****************CLOCKWISE SPIRAL SQUARE*********************
//****************Author: Petros Simidyan**********************
/////////////////////////////////////////////////////////////////
#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;


inline void fillRight(vector<vector<int>>& a, int& i, int& j, int count, int& output)
{
	while (count--)
		a[i][j++] = output++;
}

inline void fillDown(vector<vector<int>>& a, int& i, int& j, int count, int& output)
{
	while (count--)
		a[i++][j] = output++;
}

inline void fillLeft(vector<vector<int>>& a, int& i, int& j, int count, int& output)
{
	while (count--)
		a[i][j--] = output++;
}

inline void fillUp(vector<vector<int>>& a, int& i, int& j, int count, int& output)
{
	while (count--)
		a[i--][j] = output++;
	i++;// going back to the new start point
	j++;
}

inline bool isOdd(int n)
{
	return n % 2 == 1;
}

inline void print2DVec(vector<vector<int>> n)
{
	for (int i = 0; i < n.size(); i++)
	{
		for (int j = 0; j < n[i].size(); j++)
			cout << setw(3) << n[i][j] << ", ";//the output looks better with setw(3)
		cout << endl;
	}
}

int main()
{
	int input;
	cout << "Please give an Integer value greater than 1: " << endl;
	cin >> input;
	if (cin.fail())
		cout << "The given string is not an integer!" << endl;
	else
		if (input <= 1)
			cout << "The given integer is less or equal to 1!" << endl;
		else {
			vector<vector<int>>	testVec(input, vector<int>(input));
			if (isOdd(input))	//need this to push the last input*input,in case that n is odd
				testVec[input / 2][input / 2] = input * input;
			int loopHelper = input - 1, i = 0, j = 0, output = 1;
			while (loopHelper > 0)//fill (input -1) numbers in each direction
			{
				fillRight(testVec, i, j, loopHelper, output);
				fillDown(testVec, i, j, loopHelper, output);
				fillLeft(testVec, i, j, loopHelper, output);
				fillUp(testVec, i, j, loopHelper, output);
				loopHelper -= 2;
			}
			cout << "Here is your clockwise spiral square matrix with " << input << " rows an columns!" << endl;
			print2DVec(testVec);
		}

	return 0;
}
