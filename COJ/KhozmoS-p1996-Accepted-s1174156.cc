#include<bits/stdc++.h>


using namespace std;
#define PB push_back
typedef unsigned long long ll;
const int MAX = 1e6 + 5;
int f[MAX][2];
int exp(int a, int b)
{
    if(!b) return 1;
    if(b == 1) return a;
    int p = exp(a , b/2);
    return (b&1 ? p*p*a : p*p);
}
int F(int x , int idx)
{
    for(int i = 2; i * i <= x ; i++)
    {
        if(x % i == 0)
        {
            while(x % i == 0)
            {
                x /= i;
                f[i][idx]++;
            }
        }
    }
    f[x][idx]++;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t;
    cin>>t;

    for(int cas = 1; t-- ; cas++){
    memset(f, 0 , sizeof(f));
    int n , m;
    cin>>n>>m;
    while(n--)
    {
        int x;
        cin>>x;
        F(x , 0);
    }
    while(m--)
    {
        int x;
        cin>>x;
        F(x , 1);
    }
    int a = 1;
    int b = 1;
    for(int i = 1 ; i < MAX ; i++)
    {
        int r = min(f[i][0] , f[i][1]);
        f[i][0] -= r;
        f[i][1] -= r;
        a *= exp(i , f[i][0]);
        b *= exp(i , f[i][1]);
    }
    cout<<"Case #"<<cas<<": "<<a<<" / "<<b<<"\n";
    }
}
