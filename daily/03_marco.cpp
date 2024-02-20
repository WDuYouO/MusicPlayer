#include<iostream>
using namespace std;

#define Max(T) T max_##T(T x, T y){\
    return x > y ? x : y;\
}
Max(int)
Max(double)
Max(string)

#define Max(T) max_##T
int main(){
    int ix=10,iy=20;
    cout<<Max(int)(ix,iy)<<endl;
    double dx=12.3,dy=45.6;
    cout<<max_double(dx,dy)<<endl;
    string sx="world",sy="hello";
    cout<<max_string(sx,sy)<<endl;

    char cx[255]="world",cy[255]="hello";
    cout<< Max(string)(cx,cy);
    return 0;
}