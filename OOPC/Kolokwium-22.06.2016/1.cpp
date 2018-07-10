// ConsoleApplication2.cpp: definiuje punkt wejścia dla aplikacji konsolowej.
//

#include "stdafx.h"
#include <iostream> 
#include <vector>
#include <utility>
using namespace std;
class Czlowiek {
	int szczescie;
public:
	Czlowiek(int szczescie)
	{
		this->szczescie = szczescie;
	}
	int getSzczescie() {
		return szczescie;
	}
};
int operator/( Czlowiek& c1, Czlowiek& c2)
{
	return c1.getSzczescie()*c2.getSzczescie();
}
ostream& operator<<(ostream& os, Czlowiek c)
{
	os << "Pomnozone szczescie" << c.getSzczescie();
	return os;
}

int main()
{
	Czlowiek p1(20);
	Czlowiek p2(20);
	p1 = p1 / p2;
	cout << p1;

	cin.get();
	return 0;
}
