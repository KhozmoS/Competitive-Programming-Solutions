#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll s , n;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);


    int t;cin>>t;

    while(t--)
    {
        cin>>s;
        ll a = s;
        a *= 2;
        a = (ll)sqrt(a);

        if(a * (a + 1) / 2 == s)
            cout<<a - 1<<"\n";
        else
            cout<<"No solution\n";
    }

    return 0;
}
