#include <bits/stdc++.h>

using namespace std;

int t , b , r , p;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>t;

    while(t--)
    {
        cin>>b>>r>>p;
        int d = 0;
        for(int i = 0 ; i < 11 ; i++)
            if(((1<<i)&b)!=((1<<i)&r))
                d++;
        //cout<<d<<"\n";
        cout<<(d<=p&&(d&1)==(p&1)?"yes\n":"no\n");
    }

}
