#ifndef ARRAY_H
#define ARRAY_H


template <typename T, int size>
class Array{
    T arr[size];
public:
    T& operator[](int &i);
   int  getSize();
};
template<typename T, int size>
T &Array::operator[](int &i){
    return arr[i];
}
int getSize(){
    return size;
}
#endif // ARRAY_H
