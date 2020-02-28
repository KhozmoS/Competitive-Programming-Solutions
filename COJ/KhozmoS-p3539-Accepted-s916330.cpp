#include <bits/stdc++.h>
#define MAXN 1000004
using namespace std;
typedef long long LL;
LL N , W ;
int  A[MAXN];
bool vale (LL n)
{
    LL sum = 0;
    for(int i = 0 ; i < N ; i++)
    if(A[i] - n > 0)
    sum += (A[i] - n);
    if(W <= sum)
    return true;
    return false;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>N>>W;
    int maximo = -1;
    for(int i = 0 ; i < N ; i++){
    cin>>A[i];
    maximo = max(maximo , A[i]);
    }
    LL ini = 1;LL fin = maximo;
     while(fin - ini > 5)
     {
        LL n = (ini + fin) / 2;
        if(vale(n))
        ini = n;
        else
        fin = n;
     }
    // cout<<fin<<" "<<ini<<"\n";
     while(!vale(fin--));

     cout<<++fin<<"\n";
    return 0;
}
