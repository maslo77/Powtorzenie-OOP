#include <iostream>
#include "array.h"
using namespace std;
int main(){

    Array<int> a(5);
    a[3] = 10;

    for(int val:a)
        cout<<val<<endl;
    return 0;
}
