#include<iostream>
using namespace std;

void Max(int x,int y){
    cout<<"1:Max(int,int)"<<endl;
}
template<class T>
void Max(T x,T y){
    cout<<"2:Max(T,T)"<<endl;
}

int main(){
    int x=10,y=20;
    Max(x,y);
    double dx=12.3,dy=45.6;
    Max(dx,dy);
    //需要隐式转换时，选择普通函数
    Max(x,dy);
    //使用<>强制使用函数模板
    Max<int>(dx,dy);
    return 0;
}