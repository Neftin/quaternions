#include"Quaternions.hpp"
//#include"Quaternions.cpp"

using namespace std;
using namespace Quaternions;

int
main(){

    Quaternion q1;
    Quaternion q2(1);
    Quaternion q3(1,1,1);
    Quaternion q4(1,1,1,1);
    Quaternion q5(2,3,4,5);
    Quaternion q6;

    q6 = q4/q5;

    for(int i = 0;i<4;i++){
        std::cout << q6.c[i] << "\n";
    }

    return 0;

}