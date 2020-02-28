#include<bits/stdc++.h>
#define MAXN 1000005
#define MOD 10000
using namespace std;
typedef long long LL;
LL TA[MAXN];
LL A[MAXN];
int N , U , Q , x , a , k;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>N>>U>>Q;
    for(int i = 0 ; i < U ; i++)
    {
        cin>>x>>k;
        if(x > 0)
        A[x - 1] += k;
        if(x < N)
        A[x + 1] += k;

        A[x] += (k + 1);
    }
    for(int i = 1 ; i <= N ; i++)
    {
       A[i] = A[i - 1] + A[i];
    }
    for(int i = 0 ; i < Q ; i++)
    {
        int a , b;
        cin>>a>>b;
        cout<<(A[b] - A[a - 1]) % MOD<<"\n";
    }
    return 0;
}
