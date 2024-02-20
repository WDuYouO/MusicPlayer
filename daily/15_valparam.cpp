#include<iostream>
using namespace std;

template<class T,size_t S=15>
class Array{
public:
    T& operator[](size_t i){
        return m_arr[i];
    }
    size_t size(){
        return S;
    }
private:
    T m_arr[S];
};
int main(){
    Array<int,10> a;
    for(int i=0;i<a.size();i++)
        a[i] = i+1;
    for(int i=0;i<a.size();i++)
        cout<< a[i] <<" ";
    cout<<endl;
    return 0;
}