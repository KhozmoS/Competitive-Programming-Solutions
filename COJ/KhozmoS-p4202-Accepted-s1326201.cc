#include <bits/stdc++.h>

using namespace std;

const int mx[] = { 0 , 1 , 0 , -1 };
const int my[] = { 1 , 0 , -1 , 0 };

char m[15][15];
bool mk[15][15];
int cnt[10] , a , b , c , d, R , C;

int get_type( char color ) {
    int h = c - a + 1;
    int w = d - b + 1;
    if(h == w) {
        return 1;
    }
    if(abs(h-w) == 3) {
        return 2;
    }
    if(w>h) {
        if(m[a][b] != color && m[c][d] != color) {
            return 3;
        }
        if(m[c][b] != color && m[a][d] != color) {
            return 4;
        }
        if(m[a][b] != color && m[a][d] != color) {
            return 5;
        }
        if(m[c][b] != color && m[c][d] != color) {
            return 5;
        }
    } else {
        if(m[a][d] != color && m[c][b] != color) {
            return 3;
        }
        if(m[a][b] != color && m[c][d] != color) {
            return 4;
        }
        if(m[a][d] != color && m[c][d] != color) {
            return 5;
        }
        if(m[a][b] != color && m[c][b] != color) {
            return 5;
        }
    }
    return 0;
}

void dfs(int x , int y , char color)
{
    mk[x][y] = true;
    a = min(a , x);
    b = min(b , y);
    c = max(c , x);
    d = max(d , y);
    for(int i = 0 ; i < 4 ; i++)
    {
        int nx = x + mx[i];
        int ny = y + my[i];
        if(m[nx][ny] == color && !mk[nx][ny ])
            dfs(nx , ny , color);
    }
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    for(int i = 1 ; i <= 10 ; i++)
        for(int j = 1 ; j <= 10 ; j++)
            m[i][j] = '.';
    cin>>R>>C;

    for(int i = 1 ; i <= R ; i++)
        for(int j = 1 ; j <= C ; j++)
        {
            cin>>m[i][j];
        }
    for(int i = 1 ; i <= R ; i++)
        for(int j = 1 ; j <= C ; j++)
        {
            if(m[i][j] != '.' && !mk[i][j])
            {
                a = 1000;
                b = 1000;
                c = 0;
                d = 0;
                char color = m[i][j];
                dfs(i,j,color);
                cnt[get_type(color)]++;
            }
        }
    for(int i = 1 ; i <= 5 ; i++)
    {
        cout<<cnt[i]<<"\n";
    }
}
