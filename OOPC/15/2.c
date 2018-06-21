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
    friend double perimeter(std::unique_ptr<Triangle> );
    friend double perimeterRef(std::unique_ptr<Triangle> &);

};
double perimeter(std::unique_ptr<Triangle> t){
    return t->a + t->b + t->c;
}
double perimeterRef(std::unique_ptr<Triangle> &t){
    return t->a + t->b + t->c;
}

int main()
{
    std::unique_ptr<Triangle> t = make_unique<Triangle>(3,4,5);
    std::cout<<perimeterRef(t)<<std::endl;
    std::cout<<(!t ? "nie" : " ")<<"istnieje\n";

    std::cout<<perimeterRef(move(t))<<std::endl;
    std::cout<<(!t ? "nie" : " ")<<"istnieje\n";
    return 0;
}
