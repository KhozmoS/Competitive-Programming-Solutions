#include <bits/stdc++.h>

using namespace std;
const int MAXN = 13000;

bool mk[MAXN];
int sol[MAXN] , cost[MAXN] , val[MAXN];

int N , M;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t;
    cin>>t;

    while(t--)
    {

    cin>>M>>N;

    for(int i = 1 ; i <= N ; i++) cin>>val[i]>>cost[i];

    mk[0] = true; int solu = -1;

    sol[0] = 0;
    for(int i = 1 ; i <= M ; i++)
    for(int j = 1 ; j <= N ; j++)
    {
      if(i - cost[j] >= 0 && sol[i] < sol[i - cost[j]] + val[j])
      sol[i] = sol[i - cost[j]] + val[j];
    }
    cout<<sol[M]<<"\n";
    //Limpiar
    for(int i = 1 ; i <= M ; i++) sol[i] = 0;

    }
    return 0;
}
