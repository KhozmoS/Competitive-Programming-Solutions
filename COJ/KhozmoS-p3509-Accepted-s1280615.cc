#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);


    long long n , r;
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>r;
        int i = n;
        long long ans = r;
        while(i--)
        {
             ans = ans*(n)/(n-1);
        }
        cout<<ans<<"\n";
    }
}
