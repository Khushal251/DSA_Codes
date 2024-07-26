#include <iostream>
using namespace std;

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int fog = 1;
        int i = 2;
        while ((i * i) <= n)
        {
            if (n % i == 0 && (i != (n / i)))
            {
                fog = 0;
                break;
            }
            i++;
        }
        if (fog == 1)
            cout << -1 << endl;
        else
            cout << i << " " << 1 << " " << n / i << endl;
    }
}