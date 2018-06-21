#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <random>
#include <functional>
#include <chrono>
using namespace std;

class WordBag
{
  vector<unique_ptr<string>> bag;
  function<int(void)> roll;
  default_random_engine generator;
  void recalDistribution(){
      uniform_int_distribution<int> distribution(0,bag.size());
        roll = bind(distribution, generator);
  }
public:
  WordBag(){
     unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
        generator  = default_random_engine(seed);
        recalDistribution();
  }
  void add(unique_ptr<string> text){
      bag.push_back(move(text));
  }
  unique_ptr<string> take(){
      int index = roll();
      unique_ptr<string> tmp = move(bag[index]);
      bag.erase(bag.begin()+index);
      recalDistribution();
      return move(tmp);

  }
};
int main()
{
    WordBag wb;
    wb.add(make_unique<string>("Ala"));
    wb.add(make_unique<string>("ma"));
    wb.add(make_unique<string>("Kota"));
    wb.add(make_unique<string>("a"));
    wb.add(make_unique<string>("Tola"));
    wb.add(make_unique<string>("krokodyla"));


    cout<<*(wb.take().release())<<endl;
    cout<<*(wb.take().release())<<endl;
    cout<<*(wb.take().release())<<endl;
    cout<<*(wb.take().release())<<endl;
    cout<<*(wb.take().release())<<endl;
    cout<<*(wb.take().release())<<endl;
    return 0;
}
