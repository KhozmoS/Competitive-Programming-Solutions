#include <bits/stdc++.h>

using namespace std;


#define f first
#define s second
#define pb push_back
#define db double
#define sz(c) (c).size()
#define all(c) (c).begin(),(c).end()

typedef long long ll;
typedef pair <int , int > ii;
typedef pair <ii , int > iii;
typedef vector <int> vi;
typedef vector <ii> vii;
typedef vector <vi> vvi;
typedef vector <vii> vvii;

const ll mod = 1e9+5;
const int MAX = 1e5+5;


// B < D*2 | D < C*2 | C < B*2

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    ll n , s;
    while( cin>>n>>s ) {
        ll ar[MAX];
        for(int i = 1 ; i <= n ; i++) cin>>ar[i];
        int in = 1;int fn = 1;

        ll sm = ar[1];bool ok = false;
        while( fn <= n ) {

            //cout<<sm<<" "<<in<<" "<<fn<<"\n";
            if(sm==s) {
                ok = true;
                break;
            }

            if(in==fn) {
                fn++;
                sm += ar[fn];
            } else if( sm < s ) {
                fn++;
                sm += ar[fn];
            } else if( sm > s ) {
                sm -= ar[in];
                in++;
            }
        }
        if(ok) {
            cout<<in<<" "<<fn<<"\n";
        } else cout<<"-1\n";
    }
}
