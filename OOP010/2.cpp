#include <iostream>
#include <vector>
using namespace std;
class Person{
  string name;
    int age;
    vector<Person*> children;
    public:
    Person(string name, int age);
    bool operator <(const Person &p)const{
     Person &operator <<=(Person &p);
    Person &operator [](int index);
    bool operator ==(const Person &p);
     string getName() const;
     int
    }

};
Person::Person(string name, int age){
    this->name = name;
    this->age = age;
}
bool Person::operator <(const Person &p)const{
    if(this->age!=p.age)
        return this->age <p.age;
    return this->name < p.name;
}
Person &Person::operator <<=( Person &p){
    for(int i = 0;i <children.size();i++){
        if(&p==children[i]){
            return *this;
        }
        children.push_back(&p);
        return *this;
    }responsible

}
Person &Person::operator[](int index){
    return *children[index];
}
bool Person::operator ==(const Person &p){
    return this->name==p.name && this->age == p.age;

}

string Person::getname()const{
    return name;
}

class Family{
    Person *p;
public:
    Family(Person *p);
    bool operator()(Person &s);
};
Family::Family(Person *p){
    this->p =p;
}
bool Family::isFamily(const Person &p, const Person &s)
{
    if(p==s)
        return true;
    for(int i = 0 ; i < p.childrenCount();i++)
        return isFamily(p[i], s);
    return false
}
bool Family::operator()(Person &s){
    return isFamily(*p,s)
}

int main()
{  /* Person a("ala", 50);
    Person b("golek", 5);
    Person c("Cela", 10);
    (a<<=b)<<=c;
    cout<<a[1].getName()<<endl;
    return 0;*/
    set<Person> s;

}
