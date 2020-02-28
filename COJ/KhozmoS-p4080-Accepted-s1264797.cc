#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll C , T;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;cin>>t;
    while(t--)
    {
        cin>>C>>T;
        if(C-(T*(T-1)/2ll) <= 0)
            cout<<"1\n";
        else   {
            if((C-(T*(T-1)/2ll)) % T == 0)
                cout<<(C-(T*(T-1)/2ll))/T<<"\n";
            else
                cout<<((C-(T*(T-1)/2ll))/T)+1<<"\n";
        }
    }

}
