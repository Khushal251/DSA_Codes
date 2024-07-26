#include <bits/stdc++.h>
using namespace std;
#define int long long int

class hero
{

    // properties
    int health = 10; // private
    char level='B';

public:
    int power = 50;

    int gethealth()
    {
        return health;
    }
    char getlevel()
    {
        return level;
    }

    void sethealth(int x)
    {
        health=x;
        
    }
    void setlevel(char h,int password)
    {
        if(password==456)
        level=h;
        
    }

};

// Access modifier are of three types :- Public, Private, Protected
// By default class is private and you cannot access the private data by hero.health
//  you can changr default private to public by writing public:

int32_t main()
{
    // creation of an object
    // hero h1;
    // cout << "size: " << sizeof(h1) << endl; // empty class has a sizeof 1
    // // cout<<h1.health<<endl;  //you cannot access it because it is private
    // cout << h1.power << endl;

    // cout<<h1.gethealth()<<endl;  //you can access the privater elements by get function
    // cout<<h1.getlevel()<<endl;

    // // h1.health=80;  //you cannot change it as it is private
    // h1.sethealth(80);
    // cout<<h1.gethealth()<<endl;
    // h1.setlevel('c',789);
    // cout<<h1.getlevel()<<endl;
    // h1.setlevel('c',456);
    // cout<<h1.getlevel()<<endl;

    // // char a='H';
    // cout<<sizeof(h1)<<endl;  //the size of int is 8 and char is 1 so according to this the total size of h1 is 8+1=9 but in real this is 16, to know the answer read about padding and greedy alignment



    //Static allocation
    hero a;
    cout<<"health is: "<<a.gethealth()<<endl;
    cout<<"level is: "<<a.getlevel()<<endl;
    cout<<"power is: "<<a.power<<endl;

    //Dynamic allocation
    hero *b=new hero;
    cout<<"health is: "<<(*b).gethealth()<<endl;
    cout<<"level is: "<<(*b).getlevel()<<endl;
    cout<<"power is: "<<(*b).power<<endl;

    cout<<"health is: "<<b->gethealth()<<endl;
    cout<<"level is: "<<b->getlevel()<<endl;
    cout<<"power is: "<<b->power<<endl;


    






    

    return 0;
}
