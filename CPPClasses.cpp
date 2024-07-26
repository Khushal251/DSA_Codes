#include <iostream>
using namespace std;

class employee
{
    private:
        int a, b, c;

    public:
        int d, e;
        void setdata(int a1, int b1, int c1);
        void getdata()
        {
            cout << "the value of a is " << a << endl;
            cout << "the value of b is " << b << endl;
            cout << "the value of c is " << c << endl;
            cout << "the value of d is " << d << endl;
            cout << "the value of e is " << e << endl;
        }
};

void employee ::setdata(int a1, int b1, int c1)
{
    a = a1;
    b = b1;
    c = c1;
}    

int main(int argc, char const *argv[])
{
    employee harry;  /*No need to write class employee harry as in structures*/
    harry.d=34;
    harry.e=89;
    // harry.a=16;  /*we can not set a value o private element like this it can only be done by a function in the class which is setdata*/ 
    harry.setdata(1,2,4);
    harry.getdata();
    // cout<<harry.a<<endl;  /*we can not print the value of a private element by ordinary method it can only be done by a funtion in the class which is getdata here*/

    return 0;
}
