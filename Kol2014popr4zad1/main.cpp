#include <iostream>

using namespace std;
class Stworek{
public:
    virtual void powiedz(string &)=0;

};
class StworekJakajacy:public Stworek{
    void powiedz(string &napis){
        //if(napis[0]>="A"  && napis[0]<="Z" || napis[0]>="a"  && napis[0]<="z"){
            cout<<napis[0]<<napis[0]<<napis;
       // }

    }
};
class StworekBezR:public Stworek{
    void powiedz(string&napis){
        for(int i = 0; i <napis.size(); i++){
            if(napis[i]='r')
                cout<<'l';
            else
            cout<<napis;
    }

}
};
int main()
{
    string napis = "Rabarbar";
   Stworek *s = new StworekJakajacy();
   Stworek *s2 = new StworekBezR();
   s2->powiedz(napis);

   s->powiedz(napis);
    return 0;
}
