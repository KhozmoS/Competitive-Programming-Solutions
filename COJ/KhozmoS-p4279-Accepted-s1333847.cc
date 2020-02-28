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

int n , t , q;
ll ar[2005];


int main()
{
   ios_base::sync_with_stdio(0);cin.tie(0);
  while(cin>>n) {
    for(int i = 1 ; i <= n ; i++){
     cin>>ar[i];
     ar[i] += ar[i-1];
    }
    ll xr = 0;
    for(int i = 1 ; i <= n ; i++){
        ll mn = ar[i-1];
        ll res = ar[i]-ar[i-1];
        for(int j = i ; j <= n ; j++){
            res =  max(res, ar[j]-mn);
            mn = min(mn , ar[j]);
            xr ^= res;
        }
    }
    cout<<xr<<"\n";
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
