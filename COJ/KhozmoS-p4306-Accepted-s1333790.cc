#include <bits/stdc++.h>

using namespace std;


typedef  long long ll;

ll a , b , ar[3] , pos[] = {0 , 1 , 2};

bool ok (ll x , ll y , ll z) {
    if((z*2 + y <= a && (z*2 + x*2) <= b) || ((x+y <= a) && ((z*3 + x + y) <= b)))
        return true;
    swap(a,b);
    if((z*2 + y <= a && (z*2 + x*2) <= b) || ((x+y <= a) && ((z*3 + x + y) <= b)))
        return true;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;cin>>t;
    while(t-- ) {
        cin>>a>>b>>ar[0]>>ar[1]>>ar[2];
        sort(pos , pos + 3);
//        cout<<pos[0]<<" "<<pos[1]<<" "<<pos[2]<<"\n";
        bool ans = false;
        do {
            if( ok (ar[pos[0]]  , ar[pos[1]] , ar[pos[2]]) )
            {
                ans = true;
            }
        } while(next_permutation(pos , pos+3));
        cout<<(ans ? "POSSIBLE\n" : "IMPOSSIBLE\n");
    }
}
