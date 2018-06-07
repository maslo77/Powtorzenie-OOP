#include <iostream>

using namespace std;
struct Point{
    double x,y;
};

std::istream& operator>>(std::istream &is, Point &p){
        is>>p.x>>p.y;
        return is;
}
std::ostream& operator<<(std::ostream &os,const6 Point &p){
     os<<p.x<<" "<<p.y;
     return os;
}
int main()
{
    Point p;
       std::cin>>p;
       std::cout<<p;

    return 0;
}
