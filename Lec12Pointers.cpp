#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int a=3;
    int* b=&a;

    cout<<"the address of a is "<<&a<<endl;
    cout<<"the address of a is "<<b<<endl;
    cout<<"the value at address b is "<<*b<<endl;



    // pointer to pointer
    int** c=&b;
    cout<<"the address of b is "<<&b<<endl;
    cout<<"the address of b is "<<c<<endl;
    cout<<"the value at address of c is "<<*c<<endl;
    cout<<"the value at address value_at(value_at(a)) is "<<**c<<endl;



    return 0;
}
