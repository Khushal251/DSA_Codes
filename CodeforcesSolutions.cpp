#include <bits/stdc++.h>
using namespace std;
#define int long long int

void printVec(vector<int> v)
{
    cout << "size : " << v.size() << endl;
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}
int isSubstring(string s1, string s2)
{
    int M = s1.length();
    int N = s2.length();

    for (int i = 0; i <= N - M; i++)
    {
        int j;

        for (j = 0; j < M; j++)
            if (s2[i + j] != s1[j])
                break;

        if (j == M)
            return 1;
    }

    return 0;
}

void printWords(string str, vector<string> &temp)
{
    string word;
    stringstream iss(str);
    while (iss >> word)
    {
        temp.push_back(word);
    }
}

void solve()
{
    int n;
    cin >> n;
    vector<string> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    int q;
    cin >> q;
    vector<string> que(q);
    for (int i = 0; i < q; i++)
    {
        cin >> q;
    }

    for (int i = 0; i < q; i++)
    {
        vector<string> temp;
        printWords(que[i], temp);
        for (int j = 0; j < n; j++)
        {
            int check=0;
            for (int k = 0; k < temp.size(); k++)
            {
                if(isSubstring(temp[k],v[j]))
                check++;

            }
            if(check==temp.size())
            {
                cout<<"quirey "<<i+1<<" is present in sentence number "<<j+1<<endl;
            }
        

        }
    }
}

int32_t main()
{
    int t;
    cin >> t;
    for (int l = 0; l < t; l++)
    {
        solve();
    }
    return 0;
}