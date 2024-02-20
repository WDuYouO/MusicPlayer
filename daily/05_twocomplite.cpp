#include<iostream>
using namespace std;
class A{
public:
    void func(){
        cout<<"A:func()"<<endl;
    }
};
template<class T>
void foo(){
    //1.检查函数模板内部出现的所有标识符是否有声明
    //sadfsaf;   
    //2.对已知类型的调用是否有效  
    //A a;
    //a.funcasdsd();//已知类型的调用
    //3.对于未知类型的调用认为都合理
    T t;
    t.asd();//未知类型
}
int main(){

    return 0;
}