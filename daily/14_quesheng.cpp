#include<iostream>
#include<typeinfo>
using namespace std;
template<class T=short,class D=int>
class CMath{
public:
    void print(){
        cout<<"m_t:  "<<typeid(m_t).name()<<"   "
            <<"m_d:  "<<typeid(m_d).name()<<endl;
    }
private:
    T m_t;
    D m_d;
};

int main(){
    CMath<float,double> m;\
    m.print();
    CMath<>m2;
    m2.print();
    return 0;
}