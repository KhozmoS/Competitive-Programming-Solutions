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
const int MAX = 1e6+5;

int mx;int mn = 1e9+5;
bool mk[MAX];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
    cin>>t;
    while(t--) {
        memset(mk , false , sizeof(mk));
        int n , m;
        cin>>n>>m;
        for(int i = 1 ; i <= m ; i++)
        {
            int x;
            cin>>x;
            mk[x] = true;
        }
        vi v;
        for(int i = 1 ; i <= n ; i++) {
            if(!mk[i])
            {
                v.pb(i);
            }
        }
        if(sz(v))
        for(int i = 0 ; i < sz(v) ; i++) {
            cout<<v[i]<<(i==(sz(v)-1) ? "\n" : " ");
        } else {
            cout<<"\n";
        }
    }

}
