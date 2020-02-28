#include <bits/stdc++.h>

using namespace std;


const int MAX = 1e4;
int f[MAX];

int exp(int a , int b)
{
    int res = 1;
    while(b)
    {
        if(b&1)
            res = (res * a) % 10;

        b >>= 1;
        a = (a*a) % 10;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t;
    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;
        int ans = 1;
        for(int i = 2 ; i <= n ; i++)
        {
            int x = i;
            int d = 2;
            while(d * d <= x)
            {
                if(x % d == 0)
                {
                    while(x % d == 0)
                    {
                        x /= d;
                        f[d]++;
                    }
                }
                d++;
            }
            f[x]++;
        }
        int r = min(f[2] , f[5]);

        f[2] -= r;
        f[5] -= r;
        int cnt = 0;

        for(int i = 2 ; i < 5000 ; i++)
              ans = (ans * exp(i , f[i])) % 10;

        cout<<ans<<"\n";
        memset(f, 0 , sizeof(f));
    }
}
