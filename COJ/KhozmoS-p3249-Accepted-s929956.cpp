#include<bits/stdc++.h>

using namespace std;
const int MAXN = 405;

int DA[MAXN][MAXN];
int DB[MAXN][MAXN];

int MA[MAXN][MAXN];
int N;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int N;
    cin>>N;
    for(int i =  1 ; i <= N ; i++)
    for(int j = 1 ; j <= N ; j++)
    {
        cin>>MA[i][j];
        DA[i][j] = DA[i - 1][j - 1] + MA[i][j];
        DB[i][j] = DB[i - 1][j + 1] + MA[i][j];
    }
   /* cout<<DA[2][2] - DA[0][0]<<" "<<DB[2][1] - DB[0][2]<<"\n";
    for(int i = 0 ; i <= N + 1 ; i++){
    for(int j = 0 ; j <= N + 1 ; j++)
    cout<<DA[i][j]<<" ";
    cout<<endl;
    }
    for(int i = 0 ; i <= N + 1 ; i++){
    for(int j = 0 ; j <= N + 1 ; j++)
    cout<<DB[i][j]<<" ";
    cout<<endl;
    }*/

    long long sol = -10000000055555;
    for(int i = 1 ; i <= N ; i++)
    {
        for(int j = 1 ; j <= N ; j++)
        {
            int k = i; int l = j;
            while(k <= N && l <= N)
            {
                long long comp = (DA[k][l] - DA[i - 1][j - 1]) - (DB[k][j] - DB[i - 1][l + 1]);
                if(sol < comp)
                sol = comp;

                k++;l++;
            }
        }
    }
    cout<<sol<<"\n";
    return 0;
}
