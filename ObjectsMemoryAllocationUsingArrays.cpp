#include <iostream>
using namespace std;

class shop
{
    int itemid[100];
    int itemprice[100];
    int counter;

public:
    int inicounter()
    {
        counter = 0;
    }

    void setprice();
    void displayprice();
};

void shop ::setprice()
{
    cout << "Enter the id of element no " << counter + 1 << endl;
    cin >> itemid[counter];

    cout << "enter the price of the item" << endl;
    cin >> itemprice[counter];
    counter++;
}

void shop ::displayprice()
{
    for (int i = 0; i < counter; i++)
    {
        cout << "the price of item with id no " << itemid[i] << " is " << itemprice[i] << endl;
    }
}

int main(int argc, char const *argv[])
{
    shop s;

    s.inicounter();
    s.setprice();
    s.setprice();
    s.setprice();
    s.setprice();
    s.setprice();
    s.displayprice();

    return 0;
}
