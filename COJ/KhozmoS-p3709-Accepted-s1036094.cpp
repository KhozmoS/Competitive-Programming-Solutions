#include <bits/stdc++.h>

using namespace std;

const int MAXN = 107;

struct cuatro{
    int p, x, y, cost;
    cuatro(){}
    cuatro(int a, int b, int c, int d){
        p = a, x = b, y = c, cost = d;
    }
};

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, -1, 0, 1};

int R, C, F;
cuatro S, E;
char M[MAXN][MAXN][MAXN];

int bfs()
{
    queue <cuatro> cola;

    cola.push(S);
    while(!cola.empty()){
        int piso = cola.front().p;
        int X = cola.front().x;
        int Y = cola.front().y;
        int costo = cola.front().cost;
        cola.pop();

        if(M[piso][X][Y] == 'E')
            return costo;

        if(M[piso][X][Y] == '#')continue;

        if(M[piso][X][Y] == '-')
        {
            if(piso + 1 < F)
                if(M[piso + 1][X][Y] == '-')
                    cola.push(cuatro(piso + 1, X, Y, costo + 1));

            if(piso - 1 >= 0)
                if(M[piso - 1][X][Y] == '-')
                    cola.push(cuatro(piso - 1, X, Y, costo + 1));
        }
        M[piso][X][Y] = '#';

        for(int i = 0; i < 4; i++)
        {
            int nx = X + dx[i];
            int ny = Y + dy[i];

            if(nx >= R || nx < 0 || ny >= C || ny < 0)continue;
            if(M[piso][nx][ny] == '#')continue;

            cola.push(cuatro(piso, nx, ny, costo + 1));
        }
    }
    return -1;
}

int main()
{
    while(true){
        scanf("%d%d%d", &R, &C, &F);
        if(R == C && C == F && R == 0)break;
        for(int k = 0; k < F; k++)
        {
            for(int i = 0; i < R; i++)
                scanf("%s", &M[k][i]);

            for(int i = 0; i < R; i++)
                for(int j = 0; j < C; j++)
                    if(M[k][i][j] == 'S'){
                        S = cuatro(k, i, j, 0);
                        break;
                    }
        }

        int sol = bfs();
        printf("%d\n", sol);
    }

    return 0;
}
