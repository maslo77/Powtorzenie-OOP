#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Point{
    float x,y;


public:
    float getX() const;
    void setX(float value);
    float getY() const;
    void setY(float value);
};

float Point::getY() const
{
return y;
}

void Point::setY(float value)
{
y = value;
}

float Point::getX() const
{
return x;
}

void Point::setX(float value)
{
x = value;
}
int main() {

    vector<Point> vec(10);
    for(int i = 0; i < vec.size();i++){
        vec[i].setX(i);
        vec[i].setY(1./(i+1));
    }
    for(int i = 0; i < vec.size();i++){
        cout<<vec[i].getX()<<","<<vec[i].getY()<<endl;
    }
        cout<<"-----------------------------------";
        sort(vec.begin();vec.end(),compY());
        for(int i = 0; i < vec.size();i++){
            cout<<vec[i].getX()<<", "<<vec[i].getY()<<endl;
        }




    return 0;
}
