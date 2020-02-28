//by pter

#include <cstdio>
#include <iostream>
#include <queue>
#include <cstdlib>

using namespace std;

const int MAX = 150;
const int INF = (1 << 30);

const int DX[] = {-1, 0, 1, 0};
const int DY[] = {0, 1, 0, -1};

typedef pair <int, int> par;

int R, C;
int M[MAX][MAX];
int costo[MAX][MAX];
queue <par> cola;

void bfs()
{
    for(int i = 0; i < R; i++)
        for(int j = 0; j < C; j++)
            costo[i][j] = INF;

    for(int i = 0; i < R; i++)
    {
        cola.push(make_pair(i, 0));
        costo[i][0] = M[i][0];
    }
    while(!cola.empty())
    {
        int f = cola.front().first;
        int c = cola.front().second;
        cola.pop();

        for(int i = 0; i < 4; i++)
        {
            int nf = f + DX[i];
            int nc = c + DY[i];
            int ncost = costo[f][c] + M[nf][nc];

            if(nf < R && nc < C && nf > -1 && nc > -1)
            {
                if(costo[nf][nc] > ncost)
                {
                    cola.push(par(nf, nc));
                    costo[nf][nc] = ncost;
                }
            }
        }
    }
}

int main()
{
    cin >> R >> C;
    for(int i = 0; i < R; i++)
        for(int j = 0; j < C; j++)
            cin >> M[i][j];

    bfs();

    int sol = INF;
    for(int i = 0; i < R; i++)
        if(costo[i][C - 1] < sol)
            sol = costo[i][C - 1];

    cout << sol << endl;

    return 0;
}
