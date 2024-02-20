#include<iostream>
using namespace std;

int max_int(int x,int y){
    return x > y ? x : y;
}

int main(){
    int nx=10;int ny=20;
    cout << max_int(nx,ny) <<endl;
    return 0;
}