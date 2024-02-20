#include<iostream>
using namespace std;
template<class T,class D>
class CMath{
public:
    static void foo(){
        cout<<"1:CMath<T,D>"<<endl;
    }
};
//局部特化
template<class T>
class CMath<T,short>{
public:
    static void foo(){
        cout<<"2:CMath<T,short>"<<endl;
    }
};
template<class T>
class CMath<T,T>{
    public:
    static void foo(){
        cout<<"3:CMath<T,T>"<<endl;
    }
};
template<class T, class D>
class CMath<T*,D*>{
public:
    static void foo(){
        cout<<"4:CMath<T*,D*>"<<endl;
    }
};
int main(){
    CMath<int,double>::foo();//1
    CMath<int,short>::foo();//2
    //CMath<short,short>::foo();匹配歧义
    //CMath<int*,int*>::foo();匹配歧义
}