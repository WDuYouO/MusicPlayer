#include<unordered_map>
using namespace std;
class ParkingSystem {
public:
    unordered_map<int,int>map;
    ParkingSystem(int big, int medium, int small) {
        map.insert(1,big);
        map.insert(2,medium);
        map.insert(3,small);
    }
    bool addCar(int carType) {
        if(map.at(carType)>0){
            map[carType]=map.at(carType)-1;
            return true;
        }
        return false;
    }
};
int main()
{
    ParkingSystem ps =  ParkingSystem(1,1,0);
    ps.addCar(1);
    //ps.addCar(2);
    //ps.addCar(3);

}