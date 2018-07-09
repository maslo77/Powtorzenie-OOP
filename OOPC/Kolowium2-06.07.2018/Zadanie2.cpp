// ConsoleApplication2.cpp: definiuje punkt wejścia dla aplikacji konsolowej.
//

#include "stdafx.h"
#include <iostream> 
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
template<typename T>
class Checker
{
public:
	bool operator()(const int & a, const int & b, const int& x)
	{
		if (a <= x && x <= b) return true;
		else return false;
	}
};
template<typename T>
vector<T> copyIfInAnyRange(const vector<T>& values, vector < pair<T, T>>& ranges, Checker<T>& checker)
{
	vector<T> valuesInAnyRange;
	for (typename vector<pair<T,T>>::iterator it = ranges.begin(); it != ranges.end(); it++)
	{
		for (auto x : values)
		{
			if (checker(it->first, it->second, x))
			{
				valuesInAnyRange.push_back(x);
			}

		}
	}
	return valuesInAnyRange;
}

int main()
{
	Checker<int> funktor;
	vector<int> val{ 2,11,4,6,8,21 };
	vector <pair<int, int>> ran;
	ran.push_back(make_pair(1, 10));
	ran.push_back(make_pair(1, 5));
	vector<int> help;
	help = copyIfInAnyRange(val, ran, funktor);
	for (auto x : help)
	{
		cout << x << " ";
	}
	cin.get();
	return 0;
}
