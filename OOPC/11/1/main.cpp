#include <iostream>
#include <algorithm>
#include <cctype>
using namespace std;
template <typename T>
T min(T a, T b){
    if(a<b)
        return a;
    else
        return b;
}
template <typename T>
T& minBetween(T *b, T *e){
    T &min=*b;
    for(T *i=b;i<e;i++){
        if(min>*i)
            min=*i;
    }
    return min;
}
template <>
string& minBetween(string *b, string *e){
    string *pos;
    string minCopy= *b;
    string current;
    transform(minCopy.begin(),minCopy.end(), minCopy.begin(), ::toupper);
    for(string *i = b; i<e; i++){
       current = *i;
       transform(current.begin(),current.end(), current.begin(), ::toupper);
    if(minCopy.compare(current)>0)
        minCopy = current;
        pos = i;
    }
    return *pos;
}

int main()
{   string a[]={"kota","Ma","Ala","aaa"};
    cout<<minBetween(a,a+4)<<endl;


    return 0;
}
