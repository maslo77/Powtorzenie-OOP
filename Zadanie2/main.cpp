#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class WordReplacer{
  string *wordArr;
  int size;
public:
    WordReplacer(string);
    string text();
};
    WordReplacer::WordReplacer(string path){
        ifstream ifs(path);
        string word;
        int size = 0;
        while(ifs>>word) size++;

        wordArr = new string[size];
        ifs.clear();
       ifs.seekg(0,ios::beg);
       for(int i =0; i < size; i++)
           ifs>>wordArr[i];
        ifs.close();
    }
    void WordReplacer::replace(unsigned int index1, unsigned int index2){
        if(index1 == 0 || index2 == 0 || index1 > size || index2 > size) return;
        string tmp = wordArr[index1-1];
        wordArr[index1-1] = wordArr[index2 - 1];
        wordArr[index2-1] = tmp;
    }*/
    string WordReplacer::text(){
        string result;
        for(int i = 0;i < size; i++)
            result+=wordArr[i]+" ";
    return result;
    }

int main()
{
    WordReplacer w("text.txt");
    w.text();
    return 0;
}
