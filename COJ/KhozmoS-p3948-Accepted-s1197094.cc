#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e6;
int B = 500;
vector <int> SQ[1000];
int rea[MAX];
void update(int pos , int v)
{
    int group = pos/B;
    int val = rea[pos];
    rea[pos] = v;
    for(int i = 0 ; i < SQ[group].size() ; i++)
        if(SQ[group][i] == val){ SQ[group][i] = v;break;}
        sort(SQ[group].begin() , SQ[group].end());
}
int query(int a , int b , int lo , int hi)
{
    int res = 0;
    int ga = a/B;
    int gb = b/B;
    for(int i = a ; i <= b && ga == (int)(i/B) ; i++)
        res += (lo <= rea[i] && hi >= rea[i]);
    if(ga == gb) return res;
    for(int i = ga+1 ; i < gb ; i++)
    {
        res += (int)((upper_bound(SQ[i].begin() , SQ[i].end() , hi) - SQ[i].begin())-(lower_bound(SQ[i].begin() , SQ[i].end() , lo) - SQ[i].begin()));
    }
    for(int i = gb*B; i <= b ; i++)
         res += (lo <= rea[i] && hi >= rea[i]);
    return res;
}
int main()
{

    ios_base::sync_with_stdio(0);cin.tie(0);
    int n,q;
    cin>>n>>q;
    for(int i = 1 ; i <= n ; i++)
    {
        cin>>rea[i];
        SQ[(int)(i/B)].push_back(rea[i]);
    }
    for(int i = 0 ; i < 500 ; i++) sort(SQ[i].begin() , SQ[i].end());
    while(q--)
    {

        int typ;cin>>typ;
        int a , b , lo , hi;
        if(typ == 1)
        {
            cin>>a>>b>>lo>>hi;
            cout<<query(a , b , lo , hi)<<"\n";
            continue;
        }
        cin>>a>>b;
        update(a , b);
    }
}
