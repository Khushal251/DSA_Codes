#include <iostream>

using namespace std;
int glo = 6;
void sum()
{
    cout << glo;
}

int main()
{
    int a = 4, b = 6;
    float c = 8.45;
    char d = 'p';
    int glo = 9;
    glo = 78;
    bool is_true=true;

    cout << "This is tutorial 4. \nand the value of a is " << a << ". \nthe value of b is " << b;
    cout << "\nthe value of c is " << c;
    cout << "\nthe value of d is " << d;
    cout << "\n" << glo;
    sum();
    cout<<"\n"<<is_true;

    return 0;
}