#include <bits/stdc++.h>

using namespace std;
const int MAX = 4e3 + 5;
const int mod = 1e4;
typedef long long ll;
#define f first
#define s second
typedef pair <int , int> par;
int abi[MAX][MAX];

int n , a , b , c , d;
void update(int x , int y , int k)
{
    for(int i = x ; i <= n ; i += (i & -i))
        for(int j = y ; j <= n ; j += (j & -j))
           abi[i][j] = (abi[i][j] + k) % mod;
}
int query(int x , int y)
{
    int sum = 0;
    for(int i = x; i > 0 ; i -= (i & -i))
        for(int j = y; j > 0 ; j -= j & -j)
          sum = (abi[i][j] + sum) % mod;

    return sum;
}
int q , u , k;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);

    cin>>n>>u>>q;
    int t = q + u;
    while(t--)
    {
        int typ;
        cin>>typ>>a>>b>>c;
        if(typ == 2)
        {
            cin>>d;
            cout<<(query(c , d) - query(a - 1 , d) - query(c , b - 1) + query(a - 1 , b - 1) + mod + mod) % mod<<"\n";
        }
        else
        {
            c %= mod;
            update(a , b , (5 * c) % mod);
            if(a + 1 <= n)
                update(a + 1 , b , (3 * c) % mod);
            if(a - 1 > 0)
                update(a - 1 , b , (3 * c) % mod);
            if(b + 1 <= n)
                update(a , b + 1 , (3 * c) % mod);
            if(b - 1 > 0)
                update(a , b - 1 , (3 * c) % mod);
            if(a + 1 <= n && b + 1 <= n)
                update(a + 1 , b + 1 , (2 * c) % mod);
            if(a + 1 <= n && b - 1 > 0)
                update(a + 1 , b - 1 , (2 * c) % mod);
            if(a - 1 > 0 && b + 1 <= n)
                update(a - 1 , b + 1 , (2 * c) % mod);
            if(a - 1 > 0 && b - 1 > 0)
                update(a - 1 , b - 1 , (2 * c) % mod);
        }
    }
    return 0;
}
