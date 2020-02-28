#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll R;

ll pot( ll b, ll e ){
    if( !e )return 1LL;
    if( e%2 == 0 )
        return pot((b*b)%R,e/2);

    return (b%R * pot(b,e-1))%R;
}

char N[1000];


ll suma( ll b, ll e ){
    if( e == 1 )return pot(b,0);
    if( e%2 == 0 ){
        return (suma(b,e/2) + (suma(b,e/2)*pot(b,(e/2) ))%R)%R;
    }
    return (suma(b,e-1) + pot(b,e-1))%R;
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    #ifdef acm
    freopen("a.in","r",stdin);
    #endif // acm

    int test;
    cin >> test;

    ll K;
    while( test-- ){

        cin >> N >> K >> R;
        int l = strlen(N);
        ll n = 0;
        for( int i = 0; i < l; i++ ){
            n = (n*10+(N[i]-'0'))%R;
        }

        ll a = pot(10,l);
        
        if( a == 1 ){
            ll sol = ((K%R)*n)%R;
            cout << sol << '\n';
            continue;
        }


        ll s = suma(a,K);
        ll sol = (s*n)%R;
        cout << sol << '\n';
    }

    return 0;
}

