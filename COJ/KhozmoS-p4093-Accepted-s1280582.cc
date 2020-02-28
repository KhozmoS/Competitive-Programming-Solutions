#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second

typedef pair <int , int> par;
typedef pair <par , int> trio;

char M[1005][1005];
char ans[3000005];
char D[1005][1005][3];
trio track[1005][1005][3];
bool mk[1005][1005][3];

par fn;


void bfs(par in)
{
    queue <trio> q;
    q.push(trio(par(in.f , in.s) , 0));
    mk[in.f][in.s][0] = true;
    bool ok = false;

    while(!q.empty())
    {
        trio node = q.front();q.pop();

        if(node.f.f==fn.f && node.f.s == fn.s && !node.s)
        {
            ok = true;
            break;
        }
        int x , y;
        //BOX IS UP
        if(!node.s)
        {
            x = node.f.f-1;
            y = node.f.s;
            //To Up
            if(M[x][y]!='#' && M[x-1][y]!='#' && !mk[x][y][2])
            {
                mk[x][y][2] = true;
                track[x][y][2] = node;
                D[x][y][2] = 'U';
                q.push(trio(par(x,y),2));
            }
            x = node.f.f+2;
            y = node.f.s;
            //To Down
            if(M[x-1][y] != '#' && M[x][y] != '#' && !mk[x][y][2])
            {
                mk[x][y][2] = true;
                track[x][y][2] = node;
                D[x][y][2] = 'D';
                q.push(trio(par(x,y),2));
            }
            x = node.f.f;
            y = node.f.s-1;
            //To Left
            if(M[x][y]!='#'&& M[x][y-1]!='#' && !mk[x][y][1])
            {
                mk[x][y][1] = true;
                track[x][y][1] = node;
                D[x][y][1] = 'L';
                q.push(trio(par(x,y),1));
            }
            //To Right
            x = node.f.f;
            y = node.f.s+2;
            if(M[x][y-1] != '#' && M[x][y] != '#' && !mk[x][y][1])
            {
                mk[x][y][1] = true;
                track[x][y][1] = node;
                D[x][y][1] = 'R';
                q.push(trio(par(x,y),1));
            }
        }
        //BOX IS HORIZONTAL
        if(node.s==1)
        {
            x = node.f.f-1;
            y = node.f.s;
            //To Up
            if(M[x][y]!='#' && M[x][y-1]!='#' && !mk[x][y][1])
            {
                mk[x][y][1] = true;
                track[x][y][1] = node;
                D[x][y][1] = 'U';
                q.push(trio(par(x,y),1));
            }
            x = node.f.f+1;
            y = node.f.s;
            //To Down
            if(M[x][y]!='#' && M[x][y-1]!='#' && !mk[x][y][1])
            {
                mk[x][y][1] = true;
                track[x][y][1] = node;
                D[x][y][1] = 'D';
                q.push(trio(par(x,y),1));
            }
            x = node.f.f;
            y = node.f.s+1;
            //To Right
            if(M[x][y]!='#' && !mk[x][y][0])
            {
                mk[x][y][0] = true;
                track[x][y][0] = node;
                D[x][y][0] = 'R';
                q.push(trio(par(x,y),0));
            }
            x = node.f.f;
            y = node.f.s-2;
            //To Left
            if(M[x][y+1]!='#' && M[x][y]!='#' && !mk[x][y][0])
            {
                mk[x][y][0] = true;
                track[x][y][0] = node;
                D[x][y][0] = 'L';
                q.push(trio(par(x,y),0));
            }
        }
        //BOX IS VERTICAL
        if(node.s==2)
        {
            x = node.f.f;
            y = node.f.s+1;
            //To Right
            if(M[x][y]!='#' && M[x-1][y]!='#' && !mk[x][y][2])
            {
                mk[x][y][2] = true;
                track[x][y][2] = node;
                D[x][y][2] = 'R';
                q.push(trio(par(x,y),2));
            }
            x = node.f.f;
            y = node.f.s-1;
            //To Left
            if(M[x][y]!='#' && M[x-1][y]!='#' && !mk[x][y][2])
            {
                mk[x][y][2] = true;
                track[x][y][2] = node;
                D[x][y][2] = 'L';
                q.push(trio(par(x,y),2));
            }
            x = node.f.f-2;
            y = node.f.s;
            //To Up
            if(M[x+1][y]!='#' && M[x][y]!='#' && !mk[x][y][0])
            {
                mk[x][y][0] = true;
                track[x][y][0] = node;
                D[x][y][0] = 'U';
                q.push(trio(par(x,y),0));
            }
            x = node.f.f+1;
            y = node.f.s;
            //To Down
            if(M[x][y]!='#' && !mk[x][y][0])
            {
                mk[x][y][0] = true;
                track[x][y][0] = node;
                D[x][y][0] = 'D';
                q.push(trio(par(x,y),0));
            }
        }
    }
    if(!ok)
    {
        cout<<"-1\n";
        return;
    }
    trio node = trio(fn , 0);
   // string ans = "";
    int cnt =0;

    while(true)
    {
        if(node.f.f==in.f && node.f.s==in.s && !node.s)
        {
            cout<<cnt<<"\n";
            while(cnt){
                cout<<ans[cnt];
                cnt--;
            }
            cout<<"\n";
            return;
        }
        cnt++;
        ans[cnt] = D[node.f.f][node.f.s][node.s];
        node = track[node.f.f][node.f.s][node.s];
    }
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);

    for(int i = 0 ; i < 1005 ; i++)
        for(int j = 0 ; j < 1005 ; j++)
            M[i][j] = '#';

    int n , m;
    cin>>n>>m;par in;
    for(int i = 1 ; i <= n ; i++)
        for(int j = 1 ; j <= m ; j++){
            cin>>M[i][j];
            if(M[i][j] == 'E')
                fn.f = i , fn.s = j;
            if(M[i][j] == 'C')
                in.f = i , in.s = j;
        }
    bfs(in);
}
