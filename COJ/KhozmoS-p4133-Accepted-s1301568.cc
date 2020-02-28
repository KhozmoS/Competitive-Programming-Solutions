#include <bits/stdc++.h>

using namespace std;

int n , cur_area , cur_per , area , per;
const int mx[] = {0 , 1 , 0 , -1};
const int my[] = {1 , 0 , -1 , 0};
char m[1005][1005];
bool mk[1005][1005];

int count(int x , int y)
{
    int res = 0;
    for(int i = 0 ; i < 4 ; i++)
    {
        int nx = x + mx[i];
        int ny = y + my[i];
        if(m[nx][ny] != '#')
            res++;
    }
    return res;
}
void bfs(int x , int y)
{
    queue <int> X;
    queue <int> Y;
    mk[x][y] = true;
    X.push(x);
    Y.push(y);
    while(!X.empty()){
        x = X.front();
        X.pop();
        y = Y.front();
        Y.pop();
        cur_per += count(x,y);
        cur_area++;

        if(cur_area > area)
        {
            area = cur_area;
            per = cur_per;
        }
        else if(cur_area == area)
            per = min(per , cur_per);
        for(int i = 0 ; i < 4 ; i++)
        {
            int nx = x + mx[i];
            int ny = y + my[i];
            if(!mk[nx][ny] && m[nx][ny] == '#'){
                X.push(nx);
                Y.push(ny);
                mk[nx][ny] = true;
              }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    for(int i = 0 ; i < 1005 ; i++)
        for(int j = 0 ; j < 1005 ; j++)
            m[i][j] = '-';

    for(int i = 1 ; i <= n ; i++)
        for(int j = 1 ; j <= n ; j++)
            cin>>m[i][j];
            
    for(int i = 1 ; i <= n ; i++)
        for(int j = 1 ; j <= n ; j++)
            if(m[i][j] == '#' && !mk[i][j])
            {
                cur_area = 0;
                cur_per = 0;
                bfs(i,j);
            }
    cout<<area<<" "<<per<<"\n";
}
