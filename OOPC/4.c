#include <iostream>
#include <memory>

using namespace std;
class Triangle{
    double a,b,c;
public:
    Triangle(double a, double b, double c)
    {
        this->a = a;
        this->b = b;
        this->c = c;
    }
    friend double perimeter(std::shared_ptr<Triangle> );
    friend double perimeterRef(std::shared_ptr<Triangle> &);

};
double perimeter(std::shared_ptr<Triangle> t){
    return t->a + t->b + t->c;
}
double perimeterRef(std::shared_ptr<Triangle> &t){
    return t->a + t->b + t->c;
}

int main()
{
    std::shared_ptr<Triangle> t = make_shared<Triangle>(3,4,5);
    std::cout<<perimeterRef(t)<<std::endl;
    std::cout<<(!t ? "nie" : " ")<<"istnieje\n";

    return 0;
}
