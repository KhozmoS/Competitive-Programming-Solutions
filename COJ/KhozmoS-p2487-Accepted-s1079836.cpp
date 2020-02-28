#include <bits/stdc++.h>

using namespace std;
const int MAXN = 13000;

bool mk[MAXN];
int sol[MAXN] , cost[MAXN] , val[MAXN];

int N , M;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>N>>M;

    for(int i = 1 ; i <= N ; i++) cin>>cost[i]>>val[i];

    mk[0] = true; int solu = -1;

    for(int i = 1 ; i <= N ; i++)
    for(int j = M - cost[i] ; j >= 0 ; j--)
    if(sol[j] || j == 0)
    {
     //mk[j + cost[i]] = true;
     sol[j + cost[i]] = max(sol[j + cost[i]] , sol[j] + val[i]);

     if(solu < sol[j + cost[i]]) solu = sol[j + cost[i]];

    }
    cout<<solu<<"\n";
    return 0;
}
