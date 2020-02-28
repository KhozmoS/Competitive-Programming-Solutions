#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e5+5;
const int MAXS = 1e8+5;

int ac[MAX],ar[MAX] , mp[MAXS] , t , n , q;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);

    cin>>t;
    while(t--) {


        cin>>n>>q;
        for(int i = 1 ; i <= n ; i++) {
            cin>>ar[i];
        }

        while(q--) {
            int T , V , D;
            cin>>T;
            for(int i = n  ; i >= 1 ; i--) {
                ac[i] = ac[i+1] + ar[i];
                mp[ac[i]]++;
            }
            long long ans = 0;
            for(int i = n ; i >= 1 ; i--) {
                V = ar[i];
                D = ac[i];
                ans += mp[(T-V)+D];
                mp[ac[i]]--;
            }
            cout<<ans;
            if(q) cout<<" ";
            else cout<<"\n";
        }

    }

}