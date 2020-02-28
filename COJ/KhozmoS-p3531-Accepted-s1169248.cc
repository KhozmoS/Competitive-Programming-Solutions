#include <bits/stdc++.h>

using namespace std;
const int MAX = (1e3+5) * 3;
#define f first
#define s second
int M[MAX][MAX] , ans;
const int mx[] = {0 , 1 , 0 , -1},
          my[] = {1 , 0 , -1 , 0};
typedef pair <int , int> node;

void bfs(int x , int y)
{
    node in = node(x , y);
    queue <node> Q;
    Q.push(in);
    M[x][y] = 2;
    while(!Q.empty())
    {
        node n = Q.front();Q.pop();
        x = n.f;
        y = n.s;

        for(int i = 0 ; i < 4 ; i++)
        {
            int xx = x + mx[i];
            int yy = y + my[i];
            if(!M[xx][yy]){ans++; continue;}
            if(M[xx][yy] == 2) continue;

            M[xx][yy] = 2;
            Q.push(node(xx, yy));
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    cin>>n;
    while(n--)
    {
        int x1 , y1 , x2 , y2;
        cin>>x1>>y1>>x2>>y2;
        x1++ , x2++ , y1++ , y2++;
        x1 += 100; x2 += 100; y1 += 100; y2 += 100;
        for(int i = y1 ; i < y2 ; i++)
            for(int j = x1 ; j <  x2 ; j++)
                M[i][j] = 1;
    }
    /*for(int i = 0 ; i <= 10 ; i++){
    for(int j = 0 ; j <= 10 ; j++)
        cout<<M[i][j];
        cout<<endl;
    }*/
    for(int i = 1 ; i < MAX ; i++)
        for(int j = 1 ; j < MAX ; j++)
           if(M[i][j] == 1)
              bfs(i , j);
    cout<<ans<<"\n";
}
