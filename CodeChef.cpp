// C++ program to find the
// three numbers
#include "bits/stdc++.h"
using namespace std;
 
// function to find 3 distinct number
// with given product
void getnumbers(int n)
{
    // Declare a vector to store
    // divisors
    vector<int> divisor;
 
    // store all divisors of number
    // in array
    for (int i = 2; i * i <= n; i++) {
 
        // store all the occurrence of
        // divisors
        while (n % i == 0) {
            divisor.push_back(i);
            n /= i;
        }
    }
 
    // check if n is not equals to -1
    // then n is also a prime factor
    if (n != 1) {
        divisor.push_back(n);
    }
 
    // Initialize the variables with 1
    int a, b, c, size;
    a = b = c = 1;
    size = divisor.size();
 
    for (int i = 0; i < size; i++) {
 
        // check for first number a
        if (a == 1) {
            a = a * divisor[i];
        }
 
        // check for second number b
        else if (b == 1 || b == a) {
            b = b * divisor[i];
        }
 
        // check for third number c
        else {
            c = c * divisor[i];
        }
    }
 
    // check for all unwanted condition
    if (a == 1 || b == 1 || c == 1
        || a == b || b == c || a == c) {
        cout << "-1" << endl;
    }
    else {
        cout << a << ' ' << b
             << ' ' << c << endl;
    }
}
 
// Driver function
int main()
{
    int n ;
    cin>>n;
    getnumbers(n);
}