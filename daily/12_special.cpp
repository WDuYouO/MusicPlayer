#include<iostream>
#include<cstring>
using namespace std;
//类模板
template<class T>
class CMath{
public:
    CMath(T const& t1, T const& t2):m_t1(t1),m_t2(t2){}
    T add(){
        return m_t1 + m_t2;
    }
private:
    T m_t1;
    T m_t2;
};
/*
//全类特化
template<>
class CMath<char* const>{
public:
    CMath<char* const>(char* const& t1,char* const& t2):m_t1(t1),m_t2(t2){

    }
    char* const add(){
        return strcat(m_t1,m_t2);
    }
private:
    char* const m_t1;
    char* const m_t2;
};
*/
//成员特化
template<>
char*const CMath<char* const>::add(){
    return strcat(m_t1,m_t2);
}
int main(){
    int x=10,y=20;
    CMath<int> m1(x,y);
    cout<<m1.add()<<endl;
    double dx=12.3,dy=45.6;
    CMath<double> m2(dx,dy);
    cout<<m2.add()<<endl;
    
    char cx[255]="hello",cy[255]="world";
    CMath<char* const> m3(cx,cy);
    cout<<m3.add()<<endl;
    return 0;
}
