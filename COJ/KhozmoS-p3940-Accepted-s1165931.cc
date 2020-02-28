#include <bits/stdc++.h>

using namespace std;
const int mod = 1e9 + 7;
const int MAX = 1e6 + 5;

int bit[MAX+3];

void update(int pos , int v)
{
    for(int i = pos ; i > 0 ; i -= (i & -i))
        bit[i] = (v + bit[i]) % mod;
}
int query(int pos)
{
    int res = 0;

    for(int i = pos ; i < MAX ; i += (i & -i))
        res = (bit[i] + res) % mod;

    return res;
}
map <int , int> id;
int ar[MAX];
int X[MAX];
int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n;
        int ans = 0;
        cin>>n;
        update(MAX , 1);
        for(int i = 0 ; i < n ; i++) {cin>>ar[i];X[i] = ar[i];}
        sort(ar , ar + n);
        int hsh = 0;
        for(int i = 0 ; i < n ; i++)
        {
            if(id.find(ar[i]) == id.end())
                 id[ar[i]] = ++hsh;
        }
        for(int i = 0 ; i < n ; i++)
        {
            int x = id[X[i]];
            int upd = query(x+1);
            update(x , upd);
            ans = (upd + ans) % mod;
        }
        cout<<ans<<"\n";

        //clean
        id.clear();
        memset(bit , 0 , sizeof(bit));
    }
}
