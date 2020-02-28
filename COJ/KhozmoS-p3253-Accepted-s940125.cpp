#include <bits/stdc++.h>

using namespace std;
map <string , bool> m;


int sol;
int t , n;
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n;
        while(n--)
        {
            string cad;
            cin>>cad;
            if(!m[cad])
            {
                sol++;
                m[cad] = 1;
            }
        }
    }
    cout<<sol<<"\n";
    return 0;
}
