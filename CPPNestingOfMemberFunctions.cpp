#include <iostream>
#include <string>
using namespace std;

class binary
{
    string s;  /*if we do not write private or public before the variable the by default it is considered as private in classes but in stuctures it is considered as public*/

               /* string s, s.length(), s.at(i) are string library functions*/ 
public :
    void read();
    void checkin();  /* if we put the function checkin in private then it will not be called outside*/
    void oncecomplement();
    void display();
};

void binary :: read()
{
    cout<<"enter a binary number"<<endl;
    cin>>s;
}

void binary :: checkin()
{
    for (int i = 0; i < s.length(); i++)
    {
        if (s.at(i)!='0' && s.at(i)!='1')
        {
            cout<<"incorrect binary formate"<<endl;
            exit(0);   /* it is used to terminate the program or let the control exit out of the program*/
        }
        // else
        // {
        //     cout<<"it is a binary formate"<<endl;
        //     exit(0);

        // }
        
    }
    
}

void binary :: oncecomplement()
{
    checkin(); /* we can call a function  in another function without writing b.checkin() technically we hide the function checkin from the user*/
    for (int i = 0; i < s.length(); i++)
    {
        if (s.at(i)=='1')
        {
            s.at(i)='0';
        }
        else if (s.at(i)=='0')
        {
            s.at(i)='1';
        }
        
    }
    
}

void binary :: display()
{
    cout<<"displaying binary numbers"<<endl;
    for (int i = 0; i < s.length(); i++)
    {
        
        cout<<s.at(i);
        
    }
    cout<<endl;
}




int main(int argc, char const *argv[]) 
{
    // opps- Classes and Objets

    // C++ --> initially called --> C within Classes by stroustroup
    // classes --> extension of structures (in c)
    // structures have limitations
    //  --> members are public
    //  --> no methods
    // classes --> structure + more
    // classes --> can have methods and properties
    // classes --> can make few members as private or public
    // structures in c++ are typedefed
    // you can declare objects along with the class decleration
    // class employee
    // {
    //     class decleration
    // }harry,rohan;
    // harry.salary=8 makes no sence

    binary b;
    b.read();
    // b.checkin(); /* comment this function here and put it in the function onescomplement()*/
    b.display();
    b.oncecomplement();
    b.display();


    return 0;
}
