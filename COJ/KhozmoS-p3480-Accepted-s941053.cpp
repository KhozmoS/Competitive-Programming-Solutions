#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
const LL MOD = 1000;
const LL MODU = 1500;
const int MAXN = 1504;

LL N , M;
int Fib[MAXN];
int sum[MAXN];
void tabla()
{
    Fib[2] = 1;
    Fib[1] = 1;
    for(int i = 3 ; i <= MAXN ; i++)
    Fib[i] = (((Fib[i - 1]) % MOD) + ((Fib[i - 2]) % MOD)) % MOD;
    for(int i = 1 ; i < MAXN ; i++)
    sum[i] = sum[i - 1] + Fib[i];
}
bool mk[1004];
int t;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    tabla();
   // cout<<Fib[1504]<<"\n";
    int sumt = sum[1500];
    cin>>t;
    while(t--){
    cin>>N>>M;
    N--;
    LL x = M / 1500;
    LL s = M % 1500;
    LL sm = sumt * x;
    sm += sum[s];
    LL y = N / 1500;
    LL g = N % 1500;
    LL sn = sumt * y;
    sn += sum[g];
    //cout<<x<<"\n";
    //N %= MODU; M %= MODU;
    cout<<sm - sn<<"\n";
    }
    return 0;
}
//1501
