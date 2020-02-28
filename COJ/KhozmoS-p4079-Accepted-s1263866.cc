#include <bits/stdc++.h>

using namespace std;
#define PB push_back
const int MAX = 1e6+1;
int ab[MAX];
typedef long long ll;
int t;

int v[MAX];
bool r[MAX];
bool mk[MAX];
vector <int> adl[MAX];

int dp[MAX];

int dfs(int node , int mx_u , int mx_d)
{
    for(int i = 0 ; i < adl[node].size() ; i++)
    {
        int nw = adl[node][i];
        mx_d = max(dfs(nw , max(max(mx_u , v[nw]) , v[node]) , 0) , mx_d);
    }
    dp[node] = max(mx_u , mx_d);
    return max(mx_d , v[node]);
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    double R , S;
    cin>>R>>S;
    double sum = 0.0;
    int n;cin>>n;
    double N = n;
    while(n--)
    {
        double a;
        cin>>a;
        sum += a;
    }
    R*=N;
    R-=sum;
    cout<<setprecision(5)<<fixed<<R/S+(2.0*N)<<"\n";
}