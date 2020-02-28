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
multiset <int> S;
multiset <int> :: iterator it;

int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;
  cin>>t;
  while(t--){
    cin>>n;
    S.clear();
    for(int i = 1 ; i <= n ; i++) {
        int x;
        cin>>x;
        S.insert(x);
    }

    int q;cin>>q;
    while(q--) {
        int p , x;
        cin>>p>>x;
        if(p==1) {
            it = S.lower_bound(x);
            if(it==S.begin()) {
                cout<<-1<<" ";
            } else if(S.size()){
                it--;
                cout<<*it<<" ";
            } else {
                cout<<-1<<" ";
            }

            it = S.upper_bound(x);

            if(it==S.end()) {
                cout<<100001<<"\n";
            } else {
                cout<<*it<<"\n";
            }
        } else if(p==2){
            S.insert(x);
        } else if(p==3) {
//            cout<<S.size()<<"asdaf\n";
            if(S.find(x)!=S.end())
                S.erase(S.find(x));
//            cout<<S.size()<<"asdaf\n";
        }
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
