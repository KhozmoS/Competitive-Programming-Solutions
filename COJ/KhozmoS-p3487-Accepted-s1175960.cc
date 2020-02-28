#include <bits/stdc++.h>

using namespace std;

const int N = 12
        , M = 22;
char out[13][23];
int arr[11][11];
string ans;
bool mk[11][11] , ready;
bool group[11][11];
int g[11][11];

bool ok(int x , int y , int d)
{
    int id = g[x][y];

    if(group[id][d]) return false;

    for(int i = 1 ; i <= 9 ; i++)
        if(arr[x][i] == d) return false;
        else if(arr[i][y] == d) return false;

    group[id][d] = true;

    return true;
}
void print()
{
    int f = 1, c = 1;
    for(int i = 1 ; i <= 11 ; i++){
        for(int j = 1 ; j <= 21 ; j++)
        {
            if(out[i][j] == '*' || (out[i][j] <= '9' && out[i][j] >= '1'))
            {
                cout<<arr[f][c];
                c++;
                if(c == 10)
                    c = 1 , f++;
            }
            else cout<<out[i][j];
        }
        cout<<"\n";
    }
}

bool check()
{
    for(int i = 1 ; i <= 9 ; i++)
        for(int j = 1 ; j <= 9 ; j++)
            for(int x = 1 ; x <= 9 ; x++)
                if(arr[x][j] == arr[i][j] && x != i) return false;
                else if(arr[i][x] == arr[i][j] && x != j) return false;
        

    return true;
}

void solve(int i , int j , int cnt)
{
    if(ready) return;


    if(cnt == 81 ){
        print();
        ready = true;
        return;
    }

    if(i > 9) return;

    if(arr[i][j] >= 1 && arr[i][j] <= 9)
    {
        if(j == 9)
            solve(i+1 , 1 , cnt);
        else
            solve(i , j+1 , cnt);
    }

    else
    for(int d = 1 ; d <= 9 ; d++)
    {
        if(!ok(i , j , d)) continue;

        arr[i][j] = d;

        if(j == 9)
            solve(i+1 , 1 , cnt + 1);
        else
            solve(i , j+1 , cnt + 1);

        arr[i][j] = -1;
        int id = g[i][j];
        group[id][d] = false;
    }
}

void build()
{
   for(int i = 1; i <= 9 ; i++){
        for(int j = 1 ; j <= 9 ; j++){
            if(i <= 3)
                if(j <= 3)
                    g[i][j] = 1;
                else if(j <= 6)
                    g[i][j] = 2;
                else
                    g[i][j] = 3;
            else if(i <= 6)
                if(j <= 3)
                    g[i][j] = 4;
                else if(j <= 6)
                    g[i][j] = 5;
                else
                    g[i][j] = 6;
            else
                if(j <= 3)
                    g[i][j] = 7;
                else if(j <= 6)
                    g[i][j] = 8;
                else
                    g[i][j] = 9;
        }
   }
}
int main()
{
   build();
   ios_base::sync_with_stdio(0);cin.tie(0);
   int curc = 1;
   int curf = 1;
   int cnt = 0;
   ready = false;
   for(int i = 1 ; i <= 11 ; i++){
        getline(cin , ans);
        ans = " " + ans;
        for(int j = 1 ; j <= 21 ; j++)
        {
            out[i][j] = ans[j];
            if(ans[j] >= '1' && ans[j] <= '9')
            {
                cnt++;
                arr[curf][curc] = ans[j] - '0';
                int id = g[curf][curc];
                group[id][ans[j] - '0'] = true;
                curc++;
                if(curc == 10)
                    curc = 1 , curf++;
            }
            else if(ans[j] == '*')
            {
                arr[curf][curc] = -1;
                curc++;
                if(curc == 10)
                    curc = 1 , curf++;
            }
        }
   }


    solve(1 , 1 , cnt);
    if(!ready) while(1);
}

/*
* * * | * * * | * * *
* * * | * * * | * * *
* * * | * * * | * * *
------+-------+------
* * * | * * * | * * *
* * * | * * * | * * *
* * * | * * * | * * *
------+-------+------
* * * | * * * | * * *
* * * | * * * | * * *
* * * | * * * | * * *
*/























