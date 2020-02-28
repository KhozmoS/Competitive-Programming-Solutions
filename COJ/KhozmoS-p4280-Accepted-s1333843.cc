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

int n , t , ar[MAX][70];

int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--) {

    cin>>n;
    for(int i = 1 ; i <= n ; i++) {
        int x;cin>>x;
        for(int j = 1 ; j <= 60 ; j++) {
            ar[i][j] = 0;
            ar[i][j] += ar[i-1][j];
        }
        ar[i][x]++;
    }
    int q;cin>>q;
    while(q--) {
        int l , r;
        cin>>l>>r;int ans = 0;
        for(int j = 1 ; j <= 60 ; j++)
            ans += (ar[r][j]-ar[l-1][j])%2;
        cout<<ans<<"\n";
    }
  }

}
/*
13
0 0 1

1 1

2 0 1

3 0 2

4 0 3

5 0 4

6 1

7 1

8 1

9 1

*/
