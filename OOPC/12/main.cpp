#include <iostream>
#include "list.h"
using namespace std;

int main()

{
    List<string> l;
    l.prepend("aa");
    l.prepend("bb");
    l.prepend("cc");
    l.display();
    cout << "Hello World!" << endl;
    return 0;
}
