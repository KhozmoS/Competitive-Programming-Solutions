#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1000;

typedef pair <int, int> par;

const int dx[] = {-1, -2, -1, 1, 2, 1};
const int dy[] = {-1, 0, 1, 1, 0, -1};

int K,H, L;
int M[MAXN][MAXN];
int costo[MAXN][MAXN];
bool mk[MAXN][MAXN];
int FILA, COL;

vector <int> bfs(int x, int y){

    vector <int> sol;
    queue <par> cola;
    cola.push(par(x, y));
    mk[x][y] = true;

    while(!cola.empty()){
        par actual = cola.front();
        cola.pop();

        if(costo[actual.first][actual.second] == L)
            sol.push_back(M[actual.first][actual.second]);

        for(int i = 0; i < 6; i++){
            int nx = actual.first + dx[i];
            int ny = actual.second + dy[i];

            if(nx <= FILA && ny <= COL && nx >= 1 && ny >= 1){
                if(!mk[nx][ny] && M[nx][ny] != 0){
                    mk[nx][ny] = true;
                    costo[nx][ny] = costo[actual.first][actual.second] + 1;
                    if(costo[nx][ny] <= L)
                        cola.push(par(nx, ny));
                }
            }
        }
    }
    return sol;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> K >> H >> L;

    FILA = 4 * K - 3;
    COL = 2 * K - 1;
    int a, b;
    int p = 2 * K + (K - 2), val = 1; int fin = K;
    for(int j = 1; j <= 2 * K - 1; j++){
        int cont = 0;
        for(int i = p; i >= fin; i--){
            if(cont & 1)
                M[i][j] = 0;
            else{
                M[i][j] = val++;
                if(val - 1 == H)
                    a = i, b = j;
            }

            cont++;
        }

        if(j < K)
            p++, fin--;
        else
            p--, fin++;
    }
    vector <int> sol = bfs(a, b);
    sort(sol.begin(), sol.end());
    cout << sol.size() << "\n";
    for(int i = 0; i < sol.size(); i++)
        cout << sol[i] << "\n";



    return 0;
}
