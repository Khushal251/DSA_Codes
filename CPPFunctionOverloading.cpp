#include<iostream>
using namespace std;

int sum(int a, int b)
{
    cout<<"using function with 2 arguments"<<endl;
    return a+b;

}

int sum(int a, int b, int c)
{
    cout<<"using function with 3 arguments"<<endl;
    return a+b+c;
}

int sum(int a, int b, int c, int d)
{
    cout<<"using function with 4 arguments"<<endl;
    return a+b+c+d;
}

int main(int argc, char const *argv[])
{

    cout<<"the sum of 3 and 4 is "<<sum(3,4)<<endl;
    cout<<"the sum of 3, 4 and 5 is "<<sum(3,4,5)<<endl;
    cout<<"the sum of 3, 4,5 and 6 is "<<sum(3,4,5,6)<<endl;
    
    return 0;
}
