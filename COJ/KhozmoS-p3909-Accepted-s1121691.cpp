#include <bits/stdc++.h>

using namespace std;


#define f first
#define s second
const int MAX = 2 * 1e5 + 5;
typedef pair <int , int> par;
par ST[MAX * 4];
int cont;

bool com1(par a , par b)
{
    if(a.f < b.f)
        return true;
    else if(a.f == b.f && a.s < b.s)
        return true;
    return false;
}
bool com2(par a , par b)
{
    if(a.s < b.s)
        return true;
    else if(a.s == b.s && a.f < b.f)
        return true;
    return false;
}
par a[MAX];
int ab[MAX];
int abi[MAX];
void update(int pos)
{
    for(int i = pos ; i < MAX ; i += (i & -i))
        ab[i] ++;
}
void update1(int pos)
{
    for(int i = pos ; i < MAX ; i += (i & -i))
        abi[i] ++;
}
int query(int pos)
{
    int res = 0;
    for(int i = pos ; i > 0 ; i -= (i & -i)) res += ab[i];

    return res;
}
int query1(int pos)
{
    int res = 0;
    for(int i = pos ; i > 0 ; i -= (i & -i)) res += abi[i];

    return res;
}
int b[MAX];
map <int , int> m;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n; cin>>n;
    int ind = 0;
    for(int i = 1 ; i <= n ; i++)
    {
        int x , y; cin>>x>>y;
        a[i].f = x;
        a[i].s = y;
        b[ind++] = x;
        b[ind++] = y;
    }
    sort(b , b + ind);
    int ki = 1;
    for(int i = 0 ; i < ind ; i++)
    {
        if(m.find(b[i]) == m.end())
        {
            m[b[i]] = ki;
            ki++;
        }
    }
    long long ans = 1e18;
    long long ve = 0;
    long long v1 = 0;
    sort(a + 1, a + n + 1 , com1);
    for(int i = 1 ; i <= n ; i++)
    {
        a[i].f = m[a[i].f];
        a[i].s = m[a[i].s];
    }
    for(int i = 1 ; i <= n ; i++)
    {
        int x = a[i].s;
        ve += i - (query(x) + 1);

        update(x);

    }

     ans = min(ans , ve + v1);
     ve = 0;
     v1 = 0;
    sort(a + 1, a + n + 1 , com2);

    for(int i = 0 ; i <= n*2; i ++){
        ab[i] = 0 ; abi[i] = 0;
    }
    for(int i = 1 ; i <= n ; i++)
    {
        int x1 = a[i].f;
        v1 += i - (query1(x1) + 1);

        update1(x1);
    }

    ans = min(ans , ve + v1);

   cout<<ans<<"\n";
    return 0;
}
