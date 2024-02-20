#include<iostream>
using namespace std;

//函数模板
template<class T>
T Max(T x,T y){
    return x > y ? x : y;
}
template<class T,class D>
void Func(D x){
}
template<class R,class T>
R Hum(T x){
    R r;
    return r;
}
int main(){
    int x=10,y=20;
    cout<<Max(x,y)<<endl;
    double dx=12.3,dy=45.6;
    cout<<Max(dx,dy)<<endl;

    //隐式推断举例2
    Func<string>(x);
    //隐式推断举例3
    //Hum<double>(y);
    return 0;
}
