#include <bits/stdc++.h>


using namespace std;
int n , k;
typedef long long ll;
int degree[30] , suma[30];

vector <int> adl[30];
vector <ll> ad[30];

bool mk[30];

string per;
map <ll , int> ids;
int id = 1;

void dfs(int node)
{
    mk[ids[node]] = true;

    for(int i = 0 ; i < ad[node].size() ; i++)
    {
        int x = ad[node][i];
        x = ids[x];
        if(mk[x]) continue;

        adl[ids[x]].push_back(ids[node]);
        adl[ids[node]].push_back(ids[x]);

        dfs(x);
    }
}
int c = 0;
void cont(int node)
{
    mk[node] = true;
    c++;
    for(int i = 0 ; i < adl[node].size() ; i++)
    {
        int x = adl[node][i];
        if(mk[x]) continue;

        cont(x);
    }
}
set<ll> S;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
     cin>>n>>k;

    for(int i = 0 ; i < n ; i++) per += "0";

    for(int i = n - 1; i >= n - k ; i--)
        per[i] = '1';
        int x;
    for(int i = 1 ; i < n ; i++)
    {
        ll a , b;
        cin>>a>>b;
        x = a;
        S.insert(a);
        S.insert(b);
        ad[a].push_back(b);
        ad[b].push_back(a);
    }
    set <ll> :: iterator it;

    for(it = S.begin() ; it != S.end() ; it++)
    {
        ids[*it] = id;
        id++;
    }
    dfs(x);
   memset(mk , false , sizeof(mk));
   if(n == k)
   {
       cout<<0<<"\n";
       return 0;
   }
   int ans = 0;

    do{
       int node;
       c = 0;
       for(int i = 0 ; i < per.size() ; i++){
            if(per[i] == '0')
                node = i+1;
            if(per[i] == '1')
            mk[i+1] = true;
       }
       cont(node);
       if(c == (n - k))
            ans++;
       memset(mk , false , sizeof(mk));
    }while(next_permutation(per.begin() , per.end()));

    cout<<ans<<"\n";

}
