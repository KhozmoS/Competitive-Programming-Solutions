#include<bits/stdc++.h>


using namespace std;

const int MAX = 1e4 + 5;
vector <int> adl[MAX];
bool mk[MAX];
int p[MAX];

bool kunh(int node)
{
    if(mk[node]) return false;

    mk[node] = true;

    for(int i = 0 ; i < adl[node].size() ; i++)
    {
        int x = adl[node][i];
        if(p[x] == -1)
        {
            p[x] = node;
            return true;
        }

        if(kunh(p[x]))
        {
            p[x] = node;

            return true;
        }
    }

    return false;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n , m;
    while(cin>>n>>m && n)
    {
        memset(p , -1 , sizeof(p));
        int ans = 0;
        for(int i = 1 ; i <= n ; i++)
            adl[i].clear();


        while(m--){int a , b; cin>>a>>b; a++; b++; adl[a].push_back(b);}

        for(int i = 1 ;i <= n ; i++)
        {
           ans += kunh(i);
           memset(mk , false , sizeof(mk));
        }

        cout<<ans<<"\n";
    }

}
