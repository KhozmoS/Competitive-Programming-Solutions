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

int n;
iii ar[MAX];

int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n;int cur = 1;
  ar[0].f.f = -1;

  while(n--) {
    int id , typ;
    cin>>id>>typ;
    if(!typ) {
        int x;cin>>x;
        ar[cur].f.f = x;
        ar[cur].f.s = id;
        ar[cur].s = ar[id].s + 1;
        cout<<ar[cur].s<<"\n";
    } else {
        if(!ar[id].s) {
            ar[cur].s = 0;
            ar[cur].f.f = -1;
            ar[cur].f.s = 0;
            cout<<ar[cur].f.f<<"\n";
        } else {
            cout<<ar[id].f.f<<"\n";
            ar[cur].s = ar[id].s-1;
            if(!ar[cur].s) {
                ar[cur].f.f = -1;
                ar[cur].f.s = 0;
            } else {
                ar[cur].f.f = ar[ar[id].f.s].f.f;
                ar[cur].f.s = ar[ar[id].f.s].f.s;
            }
           // cout<<ar[id].f.s<<"\n";
        }
    }
    cur++;
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
