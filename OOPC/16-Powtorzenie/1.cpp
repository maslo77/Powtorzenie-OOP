// ConsoleApplication1.cpp: definiuje punkt wejścia dla aplikacji konsolowej.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <map>
#include <list>
using namespace std;
template<typename T>
map<T,int> count(list<T>& arg)
{
	map<T, int> result;
	for (auto it = arg.begin(); it != arg.end(); it++)
	{
		auto it2 = result.find(*it);
		if (it2 == result.end())
			result.insert(pair<T, int>(*it, 1));
		else
			it2->second++;
	
		}
	return result;
}

int main()
{	
	list <char> l = { 'a','b','c','d','c','d','a' };
	map<char, int> r = count(l);
	for (auto elem : r)
	{
		cout << elem.first << " " <<  elem.second << endl;
	}
	cin.get();
    return 0;
}

