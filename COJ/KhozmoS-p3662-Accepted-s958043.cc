#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < n; i++)
#define FAB(i, a, b) for(int i = a; i < b; i++)
#define mp make_pair
#define pb push_back
#define SD(n) scanf("%d",&n)
#define SDD(n,m) scanf("%d%d",&n,&m)
#define zero(n) memset(n,0,sizeof(n))
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;



vector<int> divisores(int n)
{
    vector<int> r;
    r.pb(1);
    for(int i = 2; i*i<=n; i++)
    {
        if(n%i==0)
        {
            if(n/i==i)
            {
                r.pb(i);
            }else{
                r.pb(i);
                r.pb(n/i);
            }
        }
    }
    sort(r.begin(),r.end());
    return r;
}
ll n;
int main()
{
    while(true)
    {
        scanf("%lld",&n);
        if(n==-1)break;
        auto sol = divisores(n);
        ll r = 0;
        FOR(i, sol.size())
        {
            r+=sol[i];
        }
        if(r==n)
        {
            cout << n << " = ";
            FOR(i, sol.size())
            {
                if(!i)
                {
                    cout <<sol[i];
                }else{
                    cout << " + "<<sol[i];
                }
            }
            cout <<"\n";
        }else{
            cout << n << " is NOT perfect.\n";
        }
    }
    return 0;
}
