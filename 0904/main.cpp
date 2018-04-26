#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
vector<int> con(vector<int> a, vector<int> b){
    set<int> s;
    s.insert(a.begin(), a.end());
    s.insert(b.begin(),b.end());
    vector<int> result(s.size());
    copy(s.begin(),s.end(),result);
    return result;
}

int main()
{
    vector<int> vec1= {1,2,4,7};
    vector<int> vec2= {2,3,5,8,10};
    vector<int> vec3= con(vec1,vec2);
    for(int i = 0; i <vec3.size();i++)
        cout<<vec3[i]<<",";
    cout << "Hello World!" << endl;
    return 0;
}
