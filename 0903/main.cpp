#include <iostream>
#include <list>
using namespace std;

void showList(list<string>::iterator b, list<string>::iterator e){
        for(list<string>::iterator it = b; it!=e; it++)
            cout<<*it;
}
int main()
{
    list<string> l;
    l.push_back("ala ");
    l.push_back("ma ");
    l.push_back("kota ");
    l.push_back("i ");
    l.push_back("tygrysa ");

    list<string>::iterator it = l.begin();

    for(int i = 0; i < 2; i++) it++;
        showList(it, l.end());

    return 0;
}
