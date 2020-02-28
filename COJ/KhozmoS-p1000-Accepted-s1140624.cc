#include <bits/stdc++.h>

using namespace std;
#define f first
#define s second
const int maxn = 1e5 + 5;
int  root , n , q , c , ans , a , b;
vector <int> adl[maxn];
map <int , bool> m;
typedef pair <int , int> par;
par paint[maxn];

void dfs(int nod , int col ,int tim)
{

    if(tim > paint[nod].s && paint[nod].f)
    {
        col = paint[nod].f;
        tim = paint[nod].s;
        if(m.find(col) == m.end())
        {
            ans++;
            m[col] = true;
        }
    }
    for(auto i : adl[nod])
        dfs(i , col , tim);
}

int main()
{
   ios_base::sync_with_stdio(0);cin.tie(0);
   cin>>a>>b; cout<<a+b;
}
