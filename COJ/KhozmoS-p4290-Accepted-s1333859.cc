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

int n , t;
ll smp[70] , p[70];

map <int , char> v;

string conv(ll x , ll b) {
    ll id = 69;
    string res = "";
    while(id--) {
        if(!id) break;
        if(p[id]+smp[id-1]<=x && p[id]) {
//            cout<<x<<" "<<p[id]<<" "<<smp[id-1]<<" "<<id<<"\n";
//            cout<<"wa\n";
            for(int i = b ; i >= 1 ; i--){
                if((p[id]*i)+smp[id-1]<=x) {

                    res += v[i];
                    x-=(p[id]*i);
                    break;
                }
            }
        }
    }
    return res;
}

int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--) {
    v.clear();
    ll m;cin>>m;

    smp[1] = 1;
    p[1] = 1;
    for(int i = 2 ; i <= 69 ; i++) {
        if(smp[i-1] <= 1e17) {
            p[i] = m * p[i-1];
            smp[i] = (smp[i-1] + p[i]);
        } else{
            p[i] = 0;
            smp[i] = 0;
        }
//        cout<<smp[i]<<"\n";
    }

    for(int i = 1 ; i <= m ; i++) {
        char c;cin>>c;
        v[i] = c;
    }
    int n;cin>>n;
    while(n--) {
        ll x;
        cin>>x;
        cout<<conv(x,m)<<"\n";
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
