#include <bits/stdc++.h>

using namespace std;
const int mod = 1e9 + 7;
const int MAX = 1e6 + 5;
set <string> A;
bool is(string x)
{
    string y = x;
    reverse(y.begin() , y.end());
    return x == y;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string cad;
        cin>>cad;
        if(is(cad)){cout<<"palindrome\n";continue;}
        bool flag = false;
        for(int i = 0 ; i < cad.size()-1 ; i++)
        {
            if(is(cad.substr(0 , i+1)) && is(cad.substr(i+1 , cad.size() - i - 1)))
                flag = true;
        }
        if(flag)
        {
            cout<<"bi-palindrome\n";
            continue;
        }
        cout<<"non-palindrome\n";
    }
}
