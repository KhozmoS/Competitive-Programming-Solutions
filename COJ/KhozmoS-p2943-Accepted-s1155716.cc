#include<bits/stdc++.h>

using namespace std;
const int MAX = 505;

int num[MAX];
vector <int> adl[MAX];
bool mk[MAX] , mkr[MAX];
int n , a , b;

void dfs(int nod)
{
   mk[nod] = true;
   for(int i = 0 ; i < adl[nod].size() ; i++)
   {
       int x = adl[nod][i];
       if(mk[x]) continue;

       num[x] = num[nod];
       dfs(x);
   }

}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    for(int i = 1 ; i <= n ; i++)
        cin>>num[i];

    while(cin>>a>>b)
        adl[a].push_back(b) , adl[b].push_back(a);

    for(int i = 1 ; i <= n ; i++)
        if(!mk[i] && num[i])
           dfs(i);
    for(int i = 1 ; i <= n ; i++)
        cout<<num[i]<<"\n";
    return 0;
}
