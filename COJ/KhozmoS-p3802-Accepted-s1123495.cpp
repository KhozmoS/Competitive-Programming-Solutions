#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    long long n;
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        cout<<n * (n + 2)<<"\n";
    }

    return 0;
}
