#include<bits/stdc++.h>

using namespace std;
const int MAXN = 100005;
int A[MAXN] , G[MAXN];
int g , a ,R;
int pta , ptg;
 void tabla()
 {
     for(int i = 1 ; i <= MAXN ; i++)
    {
        if(__gcd(a , i) == 1)
        A[i] = A[i - 1] + 1;
        else
        A[i] += A[i - 1];
    }
    for(int i = 1 ; i <= MAXN ; i++)
    {
        if(__gcd(g , i) == 1)
        G[i] = G[i - 1] + 1;
        else
        G[i] += G[i - 1];
    }
 }
int main()
{
   ios_base::sync_with_stdio(0);cin.tie(0);
   cin>>g>>a;
   tabla();
   cin>>R;
    while(R--)
    {
        int i , j , k , l , rra , rrg;
        cin>>i>>j>>k>>l;
        rra = G[j] - G[i - 1];
        rrg = A[l] - A[k - 1];
        int ra , rg;
        cin>>ra>>rg;
        if(ra != rra)
        pta--;
        else pta += 2;
        if(rg != rrg)
        ptg--;
        else ptg += 2;
    }
      if(ptg == pta) cout<<"Draw\n";
      else if(ptg > pta) cout<<"Garfield wins\n";
      else cout<<"Anders wins\n";

    return 0;
}
