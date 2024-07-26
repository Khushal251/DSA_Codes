#include <iostream>
using namespace std;

// Inheretence
class Human
{

private:
    int height;

public:
    int weight;

private:
    int age;

public:
    int getAge()
    {
        return this->age;
    }

    void setWeight(int w)
    {
        this->weight = w;
    }
};

class Male : public Human
{

public:
    string color;

    void sleep()
    {
        cout << "Male Sleeping" << endl;
    }

    int getHeight()
    {
        // return this->height;
    }
};


// Single Inheretence
class Animal
{

public:
    int age;
    int weight;

public:
    void speak()
    {
        cout << "Speaking " << endl;
    }
};

class Dog : public Animal
{
};


// Multiple Inheretence
class Animal
{

public:
    int age;
    int weight;

public:
    void bark()
    {
        cout << "Barking " << endl;
    }
};

class Human
{
public:
    string color;

public:
    void speak()
    {
        cout << "Speaking " << endl;
    }
};

class Hybrid : public Animal, public Human
{
};


// Multi Level Inheretence
class Animal
{

public:
    int age;
    int weight;

public:
    void speak()
    {
        cout << "Speaking " << endl;
    }
};

class Dog : public Animal
{
};

class GermanShepherd : public Dog
{
};


// Hierarchical Inheritance
class A
{

public:
    void func1()
    {
        cout << "Inside Funcion 1" << endl;
    }
};

class B : public A
{
public:
    void func2()
    {
        cout << "Inside Funcion 2" << endl;
    }
};

class C : public A
{
public:
    void func3()
    {
        cout << "Inside Funcion 3" << endl;
    }
};


//Ambugity
class A {
    public:

    void func() {
        cout << " I am A" << endl;
    }
};

class B {
    public:

    void func() {
        cout << " I am B" << endl;
    }
};

class C: public A, public B {


};



// Polimorphism

class A {

    public:
    void sayHello() {
        cout << "Hello Love Babbar" << endl;
    }
    
    int sayHello(char name) {
        cout << "Hello Love Babbar" << endl;
        return 1;
    }

    void sayHello(string name) {
        cout << "Hello " << name  << endl;
    }

};

class B {
    public:
    int a;
    int b;

    public: 
    int add() {
        return a+b;
    }

    void operator+ (B &obj) {
/*        int value1 = this -> a;
        int value2 = obj.a;
        cout << "output " << value2 - value1 << endl; 
        */
       cout << "Hello Babbar" << endl;
    }

    void operator() () {
        cout << "main Bracket hu " << this->a << endl;
    }

};

class Animal {
    public:
    void speak() {
        cout << "Speaking "<< endl;
    }
};

class Dog: public Animal {

    public:
    void speak() {
        cout << "Barking " << endl;
    }


};


// Friend Function
class GFG {
private:
    int private_variable;
 
protected:
    int protected_variable;
 
public:
    GFG()
    {
        private_variable = 10;
        protected_variable = 99;
    }
 
    // friend class declaration
    friend class F;
};
 
// Here, class F is declared as a
// friend inside class GFG. Therefore,
// F is a friend of class GFG. Class F
// can access the private members of
// class GFG.
class F {
public:
    void display(GFG& t)
    {
        cout << "The value of Private Variable = "
             << t.private_variable << endl;
        cout << "The value of Protected Variable = "
             << t.protected_variable;
    }
};

// Friend Function 2
class base {
private:
    int private_variable;
 
protected:
    int protected_variable;
 
public:
    base()
    {
        private_variable = 10;
        protected_variable = 99;
    }
     
      // friend function declaration
    friend void friendFunction(base& obj);
};
 
 
// friend function definition
void friendFunction(base& obj)
{
    cout << "Private Variable: " << obj.private_variable
         << endl;
    cout << "Protected Variable: " << obj.protected_variable;
}


// Static Function
class Hero {
    private:
    int health;

    public:
    char *name;
    char level;
    static int timeToComplete;

    Hero() {
        cout << "Simple constructor called" << endl;
        name = new char[100];
    }

    //Paramerterised Constructor
    Hero(int health) {
        this -> health = health;
    }

    Hero(int health, char level) {
        this -> level = level;
        this -> health = health;
    }

    //copy constructor
    Hero(Hero& temp) {

        // char *ch = new char[strlen(temp.name) + 1];
        // strcpy(ch, temp.name);
        // this->name = ch;

        cout << "Copy constructor called" << endl;
        this->health = temp.health;
        this->level = temp.level;
    }

    void print(){
        cout << endl;
        cout << "[ Name: " << this->name<< " ,";
        cout << "health: " << this->health << " ,";
        cout <<"level: " << this->level << " ]";
        cout << endl << endl;
    }

    int getHealth() {
        return health;
    }

    char getLevel() {
        return level;
    }

    void setHealth(int h) {
        health = h;
    }

    void setLevel(char ch) {
        level = ch;
    }

    void setName(char name[]) {
        // strcpy(this->name, name);
    }

    static int random() {
        return timeToComplete ;
    }

    //Destructor
    ~Hero() {   
        cout << "Destructor bhai called" << endl;
    }

};

int Hero::timeToComplete = 5;
 
int main()
{

    Male m1;
    // cout << m1.height << endl;

    /*
        Male object1;
        cout << object1.age << endl;
        cout << object1.weight << endl;
        cout << object1.height << endl;

        cout << object1.color << endl;

        object1.setWeight(84);
        cout << object1.weight << endl;
        object1.sleep();
        */

    return 0;
}