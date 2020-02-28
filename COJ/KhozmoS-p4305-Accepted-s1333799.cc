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

int n , t , ar[MAX] , q;


int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--) {
    string in;
    cin>>in;
    int ans = 0;
    in += "b";
    bool ok = false;
    for(int i = 0 ; i < sz(in) ; i++) {
        if(in[i]=='a') {
            int cnt = 0;
            while(in[i]=='a'&&i<sz(in)) i++;
            ans += (ok?2:1);
            i--;
        } else {
            ok = true;
        }
    }
    cout<<ans<<"\n";
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
