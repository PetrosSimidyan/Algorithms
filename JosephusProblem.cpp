
//////////////////////////////////////////////////////////////////
//////**************	 Josephus Problem
//////****************Author: Petros Simidyan
////*****************
#include <iostream>
struct People
{
	bool *isAlife;
	int size;
	People(const int& size = 20)
	{
		this->size = size;
		isAlife = new bool[size];
		for (int i = 0; i < size; i++)
			isAlife[i] = true;
	}
	~People() { delete[]isAlife; }

	bool operator[](const int& index) const
	{
		if (index < 0 || index >= size)
		{
			std::cerr << "Index out of bound!" << std::endl;
			std::cin.get();
		}
		return isAlife[index];
	}
	void kill(const int& killer, const int& victim) const
	{
		std::cout << "The " << killer + 1 << ". person kills " << victim + 1 << ". person!" << std::endl;
		isAlife[victim] = false;
	}
	void giveSword(const int& killer) const
	{
		std::cout << "The " << killer + 1 << ". person receives the sword!" << std::endl;
	}
};
//this function does all work: p is the list of persons, killer is the index of the person who has sword
//curPerson means current person is just the current index, counter is the number of persons, who are alife 
void josephus(const People& p, const int& killer, const int& curPerson, const int& counter)
{
	//if current person is out of range the function should start with index 0
	if (curPerson >= p.size)
		return josephus(p, curPerson, curPerson%p.size, counter);
	//if the killer index<0 means that there is no killer with sowrd
	//the function give the killer the current person index, only if the person is not dead 
	if (killer < 0 && p[curPerson])
	{
		p.giveSword(curPerson);
		return josephus(p, curPerson, curPerson + 1, counter);
	}
	//function have killer and the current person is alife
	//function kills current person and decrease the counter
	if (p[curPerson])
	{
		p.kill(killer, curPerson);
		//counter=2 means, that only killer is alife
		//the function prints the name of last person 
		//who is alife, in this case- killer
		if (counter == 2)
		{
			std::cout << "The only alife person is " << killer << std::endl;
			return;
		}
		return josephus(p, -1, curPerson + 1, counter - 1);
	}
	else
		//currentperson  is already dead, so function skips it
		return josephus(p, killer, curPerson + 1, counter);
}

int main()
{
	People p(13);
	josephus(p, 0, 1, p.size);
	return 0;
}