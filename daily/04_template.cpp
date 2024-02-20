#include<iostream>
using namespace std;
 class Integer{
public:
    Integer(int i ):m_i(i){}
    bool operator>(Integer const& that)const{
        return m_i > that.m_i;
    }
private:
    int m_i;
 };
//函数模板
template<class T>
T Max(T x,T y){
    return x > y ? x : y;
}

int main(){
    int x=10,y=20;
    cout<<Max<int>(x,y)<<endl;
    double dx=12.3,dy=45.6;
    cout<<Max<double>(dx,dy)<<endl;

    Integer ix=100,iy=200;
    Max<Integer>(ix,iy);
    return 0;
}
