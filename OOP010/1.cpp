#include <iostream>

using namespace std;
struct vec3{
    float x,y,z;
};
vec3 operator +(const vec3 &v, const vec3 &w){
    /*vec3 result;
    result.x = v.x+w.x;
    result.y = v.y+w.y;
    result.z = v.z+w.z;
    return result;*/
    return {v.x+w.x,v.y+w.y,v.z+w.z};
}
int main()
{
    vec3 a{1,2,3};
    vec3 b{4,5,6};
    vec3 c= a+b;
    cout<<c.x<<", "<<c.y<<", "<<c.z<<endl;
    return 0;
}
