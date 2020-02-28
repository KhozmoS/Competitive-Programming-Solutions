#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define f first
#define s second
#define PB push_back

map <int , int> mp;
typedef pair <int , int> par;
typedef pair <par , int> trio;
int n , t;
par ar[111111];

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>t;
    while(t--)
    {
        int ac[111111];
        bool mk[111111];

        memset(ac , 0 , sizeof(ac));
        memset(mk , 0 , sizeof(mk));

        cin>>n;
        vector <trio> v;
        for(int i = 1 ; i <= n ; i++){
            cin>>ar[i].f>>ar[i].s;
            v.PB(trio(par(ar[i].f , 0) , i));
            v.PB(trio(par(ar[i].s , 1) , i));
        }
        queue <int> q;
        sort(v.begin() , v.end());
        int ans = 0;
        for(int i = 0 ; i < v.size() ; i++)
        {
            if(v[i].f.s && !mk[v[i].s])
            {
                while(!q.empty())
                {
                    int x = q.front();
                    mk[x] = true;
                    q.pop();
                }
                ans++;
            }
            if(!v[i].f.s)
                q.push(v[i].s);
        }
        cout<<ans<<"\n";
    }
}
