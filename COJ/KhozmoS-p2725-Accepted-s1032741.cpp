#include <bits/stdc++.h>

using namespace std;

const int MAXN = 55;

int N;
char M[MAXN][MAXN];
char aux[MAXN][MAXN];

int check(){

    int sol = 0;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++){
            int c = j, cont = 0;
            while(c + 1 < N && M[i][c] == M[i][c + 1])
                c++, cont++;
            sol = max(sol, cont + 1);
        }
    for(int j = 0; j < N; j++)
        for(int i = 0; i < N; i++){
            int c = j, cont = 0;
            while(c + 1 < N && M[c][i] == M[c + 1][i])
                c++, cont++;
            sol = max(sol, cont + 1);
        }
    return sol;
}

int fun(int x, int y){
    int sol = 0;
    if(x - 1 >= 0){
        swap(M[x][y], M[x - 1][y]);
        sol = max(sol, check());
        swap(M[x][y], M[x - 1][y]);
    }

    if(y + 1 < N){
        swap(M[x][y], M[x][y + 1]);
        sol = max(sol, check());
        swap(M[x][y], M[x][y + 1]);
    }

    if(x + 1 < N){
        swap(M[x][y], M[x + 1][y]);
        sol = max(sol, check());
        swap(M[x][y], M[x + 1][y]);
    }

    if(y - 1 >= 0){
        swap(M[x][y], M[x][y - 1]);
        sol = max(sol, check());
        swap(M[x][y], M[x][y - 1]);
    }
    return sol;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);

    cin >> N;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            cin >> M[i][j];

    /*swap(M[0][0], M[3][3]);
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++)
            cout << M[i][j];
        cout << endl;
    }*/

    int sol = 0;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            sol = max(sol, fun(i, j));

    cout << sol << "\n";
    return 0;
}
