#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
double ans;
double sn = 0.866025404;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
    cin>>t;

    while(t--)
    {
     ll  b , x;
     cin>>b>>x;
     if(x > 32){ cout<<"-1\n"; continue;}
     ll dif = pow(2 , x);
     if(b - dif > 0) cout<<b - dif<<"\n";
     else if(b + dif <= 1e9)cout<<b + dif<<"\n";
     else cout<<"-1\n";
    }
}
