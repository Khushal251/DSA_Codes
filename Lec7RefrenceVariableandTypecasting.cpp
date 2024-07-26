#include <iostream>
using namespace std;

int c=45;
int main(int argc, char const *argv[])
{
    // int a, b;
    // cout << "enter the value of a: ";
    // cin >> a;
    // cout << "enter the value of b: ";
    // cin >> b;
    // cout << "the sum of the values of a and b is: " << a + b<<endl;

    // int c=12;
    // cout<<"the value of local c is: "<<c<<endl;
    // cout<<"the value of global c is: "<<::c<<endl;    // :: this operator takes the global variable even if the local variable is present

    
    // float a= 34.45f;
    // long double b= 34.45l;
    // // here 34.45 is a long double by default but by putting f and l we can make it float or long double
    // cout<<"the size of 34.45 is: "<<sizeof(34.45)<<endl;
    // cout<<"the size of 34.45f is: "<<sizeof(34.45f)<<endl;
    // cout<<"the size of 34.45F is: "<<sizeof(34.45F)<<endl;
    // cout<<"the size of 34.45l is: "<<sizeof(34.45l)<<endl;
    // cout<<"the size of 34.45L is: "<<sizeof(34.45L)<<endl;



    // //refrence variables
    // float x=56.1;
    // float &y=x;
    // cout<<x<<endl;
    // cout<<y<<endl;



    //typecasting
    int a=45;
    float b=45.46;
    cout<<"the value of a is: "<<(float)a<<endl;
    cout<<"the value of a is: "<<float(a)<<endl;    //(float)a=float(a);
    int c= int(a);

    cout<<"the value of b is: "<<(float)b<<endl;
    cout<<"the value of b is: "<<float(b)<<endl;


    
    return 0;
}