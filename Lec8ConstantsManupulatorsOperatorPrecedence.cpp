// //CONSTANTS
// #include <iostream>
// using namespace std;

// int main(int argc, char const *argv[])
// {
//     // int a=12;
//     // cout<<"the value of a is "<<a<<endl;
//     // a=45;
//     // cout<<"the value of a is "<<a<<endl;

//     const int a=12;    //by putting const before daata type we cannot change the value of that variable furthur in the program
//     cout<<"the value of a is "<<a<<endl;
//     a=45;     //it will gives an error
//     cout<<"the value of a is "<<a<<endl;
    
//     return 0;
// }



// //MANUPULATORS
// #include <iostream>
// #include <iomanip>
// using namespace std;

// int main(int argc, char const *argv[])
// {
//     int a=3,b=78,c=1233,d=12345678;
//     cout<<"the value of a without setw  is"<<a<<endl;
//     cout<<"the value of b without setw  is"<<b<<endl;
//     cout<<"the value of c without setw  is"<<c<<endl;
//     cout<<"the value of d without setw  is"<<d<<endl;

//     cout<<"the value of a with setw is"<<setw(4)<<a<<endl;
//     cout<<"the value of b with setw is"<<setw(4)<<b<<endl;
//     cout<<"the value of c with setw is"<<setw(4)<<c<<endl;
//     cout<<"the value of d with setw is"<<setw(4)<<d<<endl;
 
//     return 0;
// }



//OPERATOR PRECEDENCE
#include <iostream>
#include <iomanip>
using namespace std;

int main(int argc, char const *argv[])
{
    int a=3, b=4;
    int c;
    c=(a*5)+b-45+8;     //which operator should be applied first
    cout<<c;            //website = en.cpprefrence.com

    return 0;
}

