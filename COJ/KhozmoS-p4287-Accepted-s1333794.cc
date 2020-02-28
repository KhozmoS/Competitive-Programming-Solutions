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

const ll mod = 1e9+7;
const int MAX = 1e6+5;
const int mx[] = {0 , 1 , 0 , -1};
const int my[] = {1 , 0 , -1 , 0};

int N , M , T;
map <ii , bool> ined;
map <ii , int> ans;

bool findIt(int x , int y ) {
    return (ined.find(ii(x,y)) != ined.end());
}

void bfs(int x , int y)
{
    int left = T;
    queue <iii> Q;

    Q.push(iii(ii(x,y),left));

    if(!findIt(x,y))
        ans[ii(x,y)] = T;

    while(!Q.empty()) {
        iii cur = Q.front();
        Q.pop();
        //cout<<left<<"\n";
        for(int i = 0 ; i < 4; i++) {
            int x = cur.f.f + mx[i];
            int y = cur.f.s + my[i];
//            cout<<x<<" "<<y<<"asd\n";
            if(cur.s>0 && !findIt(x,y) && ans.find(ii(x,y)) == ans.end() &&  ans[ii(x,y)] < cur.s) {
                // cout<<x<<" "<<y<<" "<<cur.s-1<<"\n";
                ans[ii(x,y)] = cur.s-1;
                Q.push(iii(ii(x,y),cur.s-1));
            }
        }
    }
}

ii plague[13];

int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);

    cin>>N>>M>>T;
    for(int i = 1 ; i <= N ; i++) {
        int x , y;cin>>x>>y;
        plague[i] = ii(x,y);
    }
    for(int i = 1 ; i <= M ; i++) {
        int x , y;cin>>x>>y;
        ined[ii(x,y)] = true;
    }
    for(int i = 1 ; i <= N ; i++)
        bfs(plague[i].f , plague[i].s);

    cout<<sz(ans)<<"\n";
}
