// ConsoleApplication1.cpp: definiuje punkt wejścia dla aplikacji konsolowej.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <map>
#include <list>
#include <string>
#include <sstream>
using namespace std;

class StringList {
	list<string> lista;
public:
	 StringList operator+(string napis) const;
	 StringList operator-(string napis)const;
		 void ShowList();
};
StringList StringList::operator+(string napis) const
{
	StringList r = *this;
	r.lista.push_back(napis);
	return r;
}
StringList StringList::operator-(string napis)const
{
	StringList r = *this;
	for (auto it = r.lista.begin(); it != r.lista.end(); it++)
	{
		if (napis == *it)
		{
			r.lista.erase(it);
			return r;
		}
	}

}
void StringList::ShowList() {
	for (auto x : lista)
	{
		cout << x << " "; 
	}
}
int main()
{	
	StringList sl;
	string a = "xd";
	string b = "ok";
	string c = "weirdstring";
	sl = sl + a;
	sl = sl + b;
	sl = sl + c;
	sl.ShowList();
	sl = sl - a;
	sl.ShowList();
	cin.get();
    return 0;
}

