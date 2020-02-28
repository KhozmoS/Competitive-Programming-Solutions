#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pb push_back
#define sz(c) (c).size()
#define db double
#define all(c) (c).begin(),(c).end()

typedef long long ll;
typedef pair <int , int >ii;
typedef pair <ii , int> iii;
typedef vector <int> vi;
typedef vector <ii> vii;
typedef vector <vi> vvi;
typedef vector <vii> vvii;

const ll mod = 1e9+7;
const int MAX = 300000+5;

vi v[MAX];
int ans , n;
int day[MAX];
int sm;
bool ok = true;
int dfs(int node , int p  ,  int k)
{
    int SZ = (int)sz(v[node])-(p!=-1);
    int dif = min(k-SZ,0);
    int sobra = max(0,k-SZ);

    for(int i = 0 ; i < v[node].size() ; i++)
    {
        int nw = v[node][i];
        if(nw == p)
            continue;

        sobra += dfs(nw , node , k);
    }
    return (sobra<0?sobra:0)+dif;
}


void bin()
{
    int in = 0;int fn = n-1;
    while(in+1<fn)
    {
        int mt = (in+fn)>>1;
        sm = 0;
        if(dfs(1 , -1 , mt) >= 0)
            fn = mt;
        else
            in = mt;
    }
    cout<<fn<<"\n";
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    for(int i = 1 ; i <= n-1 ; i++){
        int a , b;
        cin>>a>>b;
        v[a].pb(b);
        v[b].pb(a);
    }
    //for(int i = 1 ; i <= 2 ; i++)
    //    cout<<day[i]<<"\n";
  //  cout<<ok(3)<<"\n";
    //cout<<dfs(1 , -1 , 3);
    bin();
}

/*
10
1 2
1 3
2 4
4 5
5 6
5 7
5 8
5 9
5 10
*/
