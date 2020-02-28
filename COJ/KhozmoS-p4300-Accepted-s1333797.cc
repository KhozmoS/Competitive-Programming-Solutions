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
const int mx[] = {0,1,1,1,0,-1,-1,-1};
const int my[] = {1,1,0,-1,-1,-1,0,1};



int t , n;

//ll R, C , stps , t , ans;
//
//void F( int x , int y , int cnt ) {
//    if(cnt==stps) {
//        ans++;
//        return;
//    }
//    M[x][y] = 1;
//
//
//    for(int i = 0 ; i < 8 ; i++) {
//        int nx = x+mx[i];
//        int ny = y+my[i];
//
//        if(nx > 0 && nx <= R && ny > 0 && ny <= C && !M[nx][ny]) {
//            F(nx,ny,cnt+1);
//        }
//    }
//    M[x][y] = 0;
//}
ll ans[] = {0,
3,
15,
75,
391,
2065,
11091,
60215,
330003,
1820869,
10103153,
56313047,
315071801,
1768489771,
9953853677
};
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>t;
    while(t--) {
        // memset(dp,-1,sizeof(dp));
        cin>>n;
        cout<<ans[n]<<"\n";
    }
}
