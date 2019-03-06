#include"Quaternions.hpp"
//#include"Quaternions.cpp"

using namespace std;
using namespace Quaternions;

void printQuaternion( const Quaternion & qq ){

    std::cout << qq.c[0] << " " << qq.c[1] << "i " << qq.c[2] << "j " << qq.c[3] << "k " << "\n";

}

int
main(){

    Quaternion q1;
    Quaternion q2(1);
    Quaternion q3(2,3,4);
    Quaternion q4(1,1,1,1);
    Quaternion q5(2,3,4,5);
    Quaternion q6;
    Quaternion q7;
    real_type  d1;

    q6 = q1+q2;
    printQuaternion( q6 );
    q6 = q1-q2;
    printQuaternion( q6 );
    q6 = -q1;
    printQuaternion( q6 );
    q6 = q3*q4;
    printQuaternion( q6 );
    q6 = q3/q4;
    printQuaternion( q6 );
    q7 = conj(q6);
    printQuaternion( q7 );
    q1 = q6*conj(q6);
    printQuaternion( q1 );
    d1 = norm(q7);
    cout << " " << d1 << " \n" 


    return 0;

}