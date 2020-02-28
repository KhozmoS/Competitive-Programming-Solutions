#include <bits/stdc++.h>

using namespace std;

typedef vector <int> VI;
struct Point
{
    int x;
    int y;
    Point(int x , int y)
    {
        this->x = x;
        this->y = y;
    }
    Point()
    {
        x = 0;
        y = 0;
    }
};
bool onSegment(Point p, Point q, Point r)
{
    if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
        q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y))
       return true;

    return false;
}
int orientation(Point p, Point q, Point r)
{
    int val = (q.y - p.y) * (r.x - q.x) -
              (q.x - p.x) * (r.y - q.y);

    if (val == 0) return 0;

    return (val > 0)? 1: 2;
}
bool doIntersect(Point p1, Point q1, Point p2, Point q2)
{
    int o1 = orientation(p1, q1, p2);
    int o2 = orientation(p1, q1, q2);
    int o3 = orientation(p2, q2, p1);
    int o4 = orientation(p2, q2, q1);
    if (o1 != o2 && o3 != o4)
        return true;

    if (o1 == 0 && onSegment(p1, p2, q1)) return true;
    if (o2 == 0 && onSegment(p1, q2, q1)) return true;
    if (o3 == 0 && onSegment(p2, p1, q2)) return true;
    if (o4 == 0 && onSegment(p2, q1, q2)) return true;

    return false;
}

int p[1005] , n , m;
Point ar[1005];
typedef pair <int , int> segm;
segm sr[1005];
#define f first
#define s second
#define PB push_back

bool graph[1005][1005];
bool mk[1005];
VI adl[1005];

void bfs(int in , int c)
{
    queue <int> cola;
    cola.push(in);
    mk[in] = true;
    while(!cola.empty())
    {
        int node = cola.front();
        cola.pop();
        p[node] = c;
        for(int i = 0 ; i < adl[node].size() ; i++)
        {
            int x = adl[node][i];
            if(mk[x]) continue;
            mk[x] = true;
            cola.push(x);
        }
    }
}
VI same_p[105][105];

int main() {



    ios_base::sync_with_stdio(0);cin.tie(0);

    int t;
    cin>>t;
    while(t--){
    for(int i = 0 ; i < 1001 ; i++) adl[i].clear();

    for(int i = 0 ; i < 100 ; i++)
         for(int j = 0 ; j < 100 ; j++)
            same_p[i][j].clear();

    memset(graph , false , sizeof(graph));
    memset(mk , false , sizeof(mk));
    memset(p , 0 , sizeof(p));

    cin>>n>>m;
    for(int i = 1 ; i <= n ; i++){
        cin>>ar[i].x>>ar[i].y;
        same_p[ar[i].x][ar[i].y].PB(i);
    }
    for(int i = 0 ; i < 100 ; i++)
         for(int j = 0 ; j < 100 ; j++)
            for(int k = 0 ; k < same_p[i][j].size() ; k++)
               for(int l = 0 ; l < same_p[i][j].size() ; l++)
                  graph[same_p[i][j][k]][same_p[i][j][l]] = true,
                  graph[same_p[i][j][l]][same_p[i][j][k]] = true;

    for(int i = 1; i <= n ; i++) graph[i][i] = true;

    for(int i = 1; i <= m ; i++){
        cin>>sr[i].f>>sr[i].s;

        graph[sr[i].f][sr[i].s] = true;
        graph[sr[i].s][sr[i].f] = true;
    }
    for(int i = 1 ; i <= m ; i++){
       for(int j = 1 ; j <= n ; j++)
       {
           if(doIntersect(ar[sr[i].f] , ar[sr[i].s] , ar[j] ,  ar[j]))
           {
               graph[sr[i].f][j] = true;
               graph[sr[i].s][j] = true;

               graph[j][sr[i].s] = true;
               graph[j][sr[i].f] = true;
           }
       }
        for(int j = 1 ; j <= m ; j++)
        {
           if(doIntersect(ar[sr[i].f] , ar[sr[i].s] , ar[sr[j].f] , ar[sr[j].s]))
           {
               graph[sr[i].f][sr[j].s] = true;
               graph[sr[i].f][sr[j].f] = true;
               graph[sr[i].s][sr[j].f] = true;
               graph[sr[i].s][sr[j].s] = true;

               graph[sr[j].f][sr[i].s] = true;
               graph[sr[j].f][sr[i].f] = true;
               graph[sr[j].s][sr[i].f] = true;
               graph[sr[j].s][sr[i].s] = true;
           }
        }
    }
    for(int i = 1 ; i <= n ; i++)
       for(int j = 1 ; j <= n ; j++)
       {
           if(graph[i][j])
           {
              adl[i].PB(j);
              adl[j].PB(i);
           }
       }
    int componet = 1;
    for(int i = 1 ; i <= n ; i++)
    {
        if(!mk[i])
            bfs(i , componet) , componet++;
    }
    int q;cin>>q;
    while(q--)
    {
        int a , b;
        cin>>a>>b;
        if(p[a] == p[b])
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    }
}
