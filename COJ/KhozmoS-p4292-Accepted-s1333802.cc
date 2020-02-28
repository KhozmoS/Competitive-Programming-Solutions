#include <bits/stdc++.h>

using namespace std;


#define f first
#define s second
#define pb push_back
#define db long double
#define sz(c) (c).size()
#define all(c) (c).begin(),(c).end()

typedef long long ll;
typedef pair <int , int > ii;
typedef pair <ii , int > iii;
typedef vector <int> vi;
typedef vector <ii> vii;
typedef vector <vi> vvi;
typedef vector <vii> vvii;

const ll mod = 1e8+5;
const int MAX = 1e6+5;
const int mx[] = {0,1,1,1,0,-1,-1,-1};
const int my[] = {1,1,0,-1,-1,-1,0,1};

bool mk[mod*2];

int A[MAX];
int S[105];

ii ans[105];

bool cmp(ii a , ii b) {
    if(a.s == b.s) {
        return a.f < b.f;
    } else {
        return a.s > b.s;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int CA , CS;
    cin>>CA>>CS;
    for(int i = 1 ; i <= CA ; i++) {
    cin>>A[i];
    mk[A[i]] = true;
    }
    for(int i = 1 ; i <= CS ; i++) {
    cin>>S[i];
    }
    for(int j = 1 ; j <= CS ; j++) ans[j].f = S[j];
    for(int i = 1 ; i <= CA ; i++) {
        for(int j = 1 ; j <= CS ; j++) {
            mk[A[i]] = false;
            if(A[i] < S[j]) {
                int x = S[j]-A[i];
                if(mk[x]) {
                    ans[j].f = S[j];
                    ans[j].s++;
                }
            }
            mk[A[i]] = true;
        }
    }
    sort(ans+1 , ans+CS+1 , cmp);
    int i = 1;
    while( CS-- ) {
        cout<<ans[i].f<<" "<<ans[i].s/2<<"\n";
        i++;
    }
}
