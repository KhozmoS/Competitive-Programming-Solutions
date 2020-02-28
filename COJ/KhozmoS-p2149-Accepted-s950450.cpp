#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000000007;
const int MAXN = 100005;

//vector <int> Fib;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t;

    cin>>t;
    string cad;
    while(t--)
    {
        cin>>cad;
        int c = 0; int C = 0;
        for(int i = 0 ; i < cad.size() ; i++)
        {
            if(cad[i] - 'a' >= 0)
            c++;
            else
            C++;
        }
        if(C == c)
        cout<<"SI\n";
        else
        cout<<"NO\n";
    }

    return 0;
}
