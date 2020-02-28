#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int MAX = 1e5+2;
ll RMQ[MAX][18];
ll gcd(ll a, ll b)
{
    return (!b ? a : gcd(b , a % b));
}
ll query(int lo , int hi)
{
    int lg = (int)__lg(hi - lo + 1);
    return gcd(RMQ[lo][lg] , RMQ[hi-(1<<lg)+1][lg]);
}
int main()
{
    //cout<<(int)__lg(2);
   // ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;

        for(int i = 0 ; i < n ; i++) cin>>RMQ[i][0];

        for(int k = 1 ; (1<<k) <= n ; k++)
            for(int i = 0 ; i + (1<<k) <= n ; i++)
               RMQ[i][k] = gcd(RMQ[i][k-1] , RMQ[i+(1<<(k-1))][k-1]);
        ll ans = 0;
        for(int i = 0 ; i < n ; i++)
        {
            int last = 1 ;ll cur = RMQ[i][0];
            while(last)
            {
                int in = -1; int fn = i;
                while(in + 3 < fn)
                {
                    int mt = (in + fn)>>1;
                    if(query(mt , i) >= cur)
                          fn = mt;
                    else
                          in = mt;
                }
                if(in < 0) in = 0;
                for(;in<=fn;in++)if(query(in,i)==cur){fn=in;break;}
               // system("pause");
                last = fn;
              //  cout<<last<<" "<<i<<" "<<in<<"\n";
               // cout<<cur<<"\n";
                ans = max((ll)(i - fn + 1) * cur , ans);
                if(!last) break;

                cur = query(fn-1 , i);
                //cout<<cur<<"\n";
            }
        }
        cout<<ans<<"\n";
        //memset(RMQ , 0 , sizeof())
    }
}

