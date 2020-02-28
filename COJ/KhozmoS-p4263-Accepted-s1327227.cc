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



int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    string a;
    cin>>a;
    int n = sz(a);
    bool ok = true;
    for(int i = 0 ; i < (n / 2) ; i++) {
        if( a[i] != a[n-i-1] ) {
            swap( a[i] , a[i+1]);
            if( a[i] != a[n-i-1] ) {
                ok = false;
            }
        }
    }
    cout<<(ok ? "Yes\n" : "No\n");

}
