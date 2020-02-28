#include<bits/stdc++.h>

#define MAXN 1007

using namespace std;
int x[MAXN] ; int y[MAXN];
int n;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    for(int i = 1; i <= n ; i++) cin>>x[i]>>y[i];
    
    int ans = 1;
    for(int i = 1 ; i <= n ; i++)
        for(int j = i+1 ; j <= n; j++){
            int cur = 2;
            for(int k = j+1 ; k <= n ; k++)
                cur += ((x[j]-x[i])*(y[k]-y[i])==(x[k]-x[i])*(y[j]-y[i]));
            ans = max(cur , ans);
        }
    cout<<ans<<"\n";
}
//((x2-x1)*(y3-y1)) == ((x3-x1)*(y2-y1))
