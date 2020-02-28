#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e6 + 5;

int abn[MAX];
int ab0[MAX] , ar[MAX];

void update0(int i , int v)
{
    for(; i < MAX ; i += (i & -i))
        ab0[i] += v;
}
void updaten(int i , int v)
{
    for(; i < MAX ; i += (i & -i))
        abn[i] += v;
}
int query0(int i , int j)
{
    --i;
    int suma = 0;
    int sumb = 0;
    for(; i > 0 ; i -= (i&-i))
        suma += ab0[i];
    for(; j > 0 ; j -= (j&-j))
        sumb += ab0[j];
    return sumb - suma;
}
int queryn(int i , int j)
{
    --i;
    int suma = 0;
    int sumb = 0;
    for(; i > 0 ; i -= (i&-i))
        suma += abn[i];
    for(; j > 0 ; j -= (j&-j))
        sumb += abn[j];
    return sumb - suma;
}

void clean()
{
    memset(ab0 , 0 , sizeof(ab0));
    memset(abn , 0 , sizeof(abn));
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n , q;
    while(cin>>n>>q)
    {
        clean();
        for(int i = 1 ; i <= n ; i++)
        {
            int x;cin>>x;
            ar[i] = x;
            if(x < 0) updaten(i , 1);
            if(x == 0) update0(i , 1);
        }
        while(q--)
        {
            char c;int a , b;
            cin>>c>>a>>b;
            if(c == 'C')
            {
                if(ar[a] < 0)
                    updaten(a , -1);
                if(ar[a] == 0)
                    update0(a , -1);
                if(b < 0) updaten(a , 1);
                if(b == 0) update0(a , 1);
                ar[a] = b;
                continue;
            }
            int zero = query0(a , b);
            int neg = queryn(a , b);
            if(zero) cout<<'0';
            else if(neg&1) cout<<'-';
            else cout<<'+';
        }
        cout<<"\n";
    }
}
