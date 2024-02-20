#include<iostream>
using namespace std;

template<class T>
class Array{
public:
    T& operator[](size_t i){
        return m_arr[i];
    }
private:
    T m_arr[10];
};
int main(){
/*    Array<int> a;
    for(int i=0;i<10;i++){
        a[i] = i+1;
    }
    for(int i=0;i<10;i++){
        cout<< a[i] <<" ";
        cout << endl;
    }
    return 0;
*/
    Array<Array<int>> m;
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            m[i][j] = i+j;
        }
    }
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            cout<< m[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}