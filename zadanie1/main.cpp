#include <iostream>

using namespace std;
    int function(char **&arr, int size){
    int newSize=0;
  for(int i = 0; i < size; i++)
  {
      if(arr[i]!=nullptr){
          newSize++;
      }
  }
  char **tmp = new char*[newSize];
    int j=0;
  for(int i = 0; i <size; i++){
      if(arr[i]!=nullptr)
      {
          tmp[j++] = arr[i];
      }
  }
  delete [] arr;
  arr=tmp;
  return newSize;

}

int main()
{
    int size=5;
    char **arr = new char*[size];
    arr[0]=new char; *(arr[0])='A';
    arr[1]=new char; *(arr[1])='B';
    arr[2]=nullptr;
    arr[3]=nullptr;
    arr[4]=new char; *(arr[4])='C';
    int a=function(arr,size);
    for(int i = 0; i < a; i++)
    {
        cout<<arr[i]<<',';
    }
    return 0;
}
