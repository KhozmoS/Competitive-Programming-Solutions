#include<bits/stdc++.h>


using namespace std;

#define x first
#define y second
#define db double
#define PB push_back
const int MAX = 300;

typedef pair <db , db> par;
db goal , vel;
int n , m;
par goph[MAX] , hole[MAX];

vector <int> adl[MAX];

bool mk[MAX]; int p[MAX];

db sq(db a)
{
    return a * a;
}
db dist(par a , par b)
{
    return sqrt(sq(a.x - b.x) + sq(a.y - b.y));
}
bool kunh(int node)
{
    if(mk[node]) return false;

    mk[node] = true;

    for(int i = 0 ; i < adl[node].size() ; i++)
    {
        int to = adl[node][i];
        if(!p[to]){
          p[to] = node;
          return true;
         }

        if(kunh(p[to]))
        {
            p[to] = node;

            return true;
        }

    }

    return false;
}

int main()
{
   ios_base::sync_with_stdio(0);cin.tie(0);

   while(cin>>n>>m>>goal>>vel)
   {
       goal *= vel;
       memset(p , 0 , sizeof(p));

       for(int i = 1 ; i <= n ; i++) cin>>goph[i].x>>goph[i].y;

       for(int i = 1 ; i <= m ; i++) cin>>hole[i].x>>hole[i].y;

       for(int i = 1 ; i <= n ; i++)
          for(int j = 1 ; j <= m ; j++)
             if(dist(goph[i] , hole[j]) <= goal)
                adl[i].PB(j);

       int ans = 0;

       for(int i = 1 ; i <= n ; i++)
       {
           ans += kunh(i);
           memset(mk , false , sizeof(mk));
       }

       cout<<n - ans<<"\n";

       for(int i = 0 ; i < MAX ; i++) adl[i].clear();
   }

}
