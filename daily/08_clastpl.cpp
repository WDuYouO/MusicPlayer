#include<iostream>
using namespace std;
//类模板
template<class T>
class CMath{
public:
    CMath(T const& t1, T const& t2):m_t1(t1),m_t2(t2){}
/*   T add(){
        在类里面实现
        return m_t1 + m_t2;
    }*/
    T add();
private:
    T m_t1;
    T m_t2;
};
//在类外实现成员函数
template<class T>
T CMath<T>::add(){
    return m_t1 + m_t2;
}
int main(){
    int x=10,y=20;
    CMath<int> m1(x,y);
    cout<<m1.add()<<endl;
    double dx=12.3,dy=45.6;
    CMath<double> m2(dx,dy);
    cout<<m2.add()<<endl;
    
    return 0;
}
