#include <bits/stdc++.h>

using namespace std;
const int MAX = 505;
map<string, int> mp_id;
bool dp1[MAX][MAX] , dp2[MAX][MAX];
int n , q;
string a , b , c;

int mierda(string x)
{
    int id1;
    if(mp_id.find(x) == mp_id.end())
        {
            int sz = mp_id.size();
            mp_id[x] = sz;
            id1 = sz;
        }
    else id1 = mp_id[x];
    return id1;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n>>q;
    for(int i = 0 ; i < MAX ; i++) dp1[i][i] = true;
    int mx = 0;
    while(n--)
    {
        int id1 , id2;
        cin>>a>>c>>b;
        if(mp_id.find(a) == mp_id.end())
        {
            int sz = mp_id.size();
            mp_id[a] = sz;
            id1 = sz;
        }
        else id1 = mp_id[a];
        if(mp_id.find(b) == mp_id.end())
        {
            int sz = mp_id.size();
            mp_id[b] = sz;
            id2 = sz;
        }
        else id2 = mp_id[b];
       // cout<<id1<<" "<<id2<<"\n";
        if(c == "is-a")
            dp1[id1][id2] = true;
        else dp2[id1][id2] = true;
        mx = max(mx , max(id1 , id2));
    }
    for(int k = 0 ; k <= mx ; k++)
        for(int i = 0 ; i <= mx ; i++)
            for(int j = 0 ; j <= mx ; j++)
            {
                dp1[i][j] = max(dp1[i][j] , (dp1[i][k] && dp1[k][j]));

                dp2[i][j] = max(dp2[i][j] , (dp2[i][k] && dp2[k][j]));
                dp2[i][j] = max(dp2[i][j] , (dp1[i][k] && dp2[k][j]));
                dp2[i][j] = max(dp2[i][j] , (dp2[i][k] && dp1[k][j]));
            }
    int cnt = 0;
    while(q--)
    {
        cnt++;
        cin>>a>>c>>b;
        int id1 = mierda(a);
        int id2 = mierda(b);

        if(c == "is-a")
            cout<<"Query "<<cnt<<": "<<(dp1[id1][id2] ? "true\n" : "false\n");
        else
            cout<<"Query "<<cnt<<": "<<(dp2[id1][id2] ? "true\n" : "false\n");
    }
}
