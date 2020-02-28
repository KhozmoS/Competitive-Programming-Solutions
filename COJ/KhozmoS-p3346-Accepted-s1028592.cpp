#include <bits/stdc++.h>

using namespace std;

const int MAXA = 11111;
const int MAXN = 1111111;

int ar[MAXN];
int cost[MAXN];
int N , T , K;
int binars(int x)
{
    int ini = 0;
    int fin = N - 1;
    while((fin - ini) > 5)
    {
       int mit = (fin + ini) / 2;
       if(ar[mit] * x <= K)
          ini = mit;
       else
          fin = mit;
    }
    for(int i = fin ; i >= ini ; i--)
    {
       if(ar[i] * x <= K)
        return i;
    }
    return 0;
}

int main()
{
   ios_base::sync_with_stdio(0);cin.tie(0);

    cin>>N>>K;
    for(int i = 0 ; i < N ; i++) cin>>ar[i];

    sort(ar , ar + N);

    cin>>T;

    for(int i = 0 ; i < T ; i++)
    {
        cin>>cost[i];
        int c = binars(cost[i]);
        int sol = 0;
        sol = N - c;
      //  cout<<c<<" ";
         cout<<--sol<<"\n";
    }

    //cout<<"\n";
   // for(int i = 0 ; i < N ; i++)
  //      cout<<ar[i]<<" ";
    return 0;
}
