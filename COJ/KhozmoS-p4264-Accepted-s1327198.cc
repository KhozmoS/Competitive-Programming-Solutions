#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pb push_back
#define db double
#define sz(c) (c).size()
#define all(c) (c).begin(),(c).end()

typedef long long ll;
typedef pair < int , int > ii;
typedef pair < ii , int > iii;
typedef vector < int > vi;
typedef vector < ii > vii;
typedef vector < vi > vvi;
typedef vector < vii > vvii;

const ll mod = 1e9+7;
const int MAX = 1e6+5;

map < int , int > vm[MAX];

int N , M , q , t , fi , x , y;
ll ans;

void update ( int r , int i , int v ) {

    for( ; i <= M ; i += (i & -i) ) {
        vm[r][i] += v;
    }
}

int query ( int r , int i ) {
    int res = 0;
    for( ; i > 0 ; i -= (i & -i))
        if( vm[r].find(i) == vm[r].end() ) res += 0;
        else res += vm[r][i];
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>N>>M>>q;

    while(q--) {
        cin>>t>>fi>>x>>y;
        if( t == 1 ) {
            update( (fi+ans) % N + 1 , x , y);
        } else {
            ans = query( (fi+ans) % N + 1 , y ) - query( (fi+ans) % N + 1 , x-1 );
            cout<<ans<<"\n";
        }
    }

}
