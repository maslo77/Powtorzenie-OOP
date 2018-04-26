#include <iostream>
#include <vector>
using namespace std;
class Point{
    float x,y;
public:
    float getX() const{return x;};
    void setX(float value){x = value;}
    float getY() const{return y;};
    void setY(float value){y = value;}
};
vector<Point> inRecangle(const vector<Point> &vec, Point p, Point q){
     vector <Point> result;
     for(int i = 0; i<vec.size();i++){
         Point &tmp = vec[i];
         if(p.getX()<=tmp.getX() && q.getX()>=tmp.getX() && p.getY()>=tmp.getY() && q.getY()<=tmp.getY()){
             result.push_back(tmp);
         }
     return result;
     }
}
int main()
{

    vector<Point> vec(10);
        for(int i = 0; i < vec.size();i++){
            vec[i].setX(i);
            vec[i].setY(2*i);
        }
        Point p,q;
        p.setX(0);
        p.setY(6);
        q.setX(6);
        q.setY(2);

        vector<Point> vec(10);
            for(int i = 0; i < vec.size();i++){
                vec[i].setX(i);
                vec[i].setY(2*i);
            }
            Point p,q;
            p.setX(0);
            p.setY(6);
            q.setX(6);
            q.setY(2);
            vector<Point> vec2;
            vec2 = inRecangle(vec, p, q);
            for(int i = 0; i < )
    cout << "Hello World!" << endl;
    return 0;
}
