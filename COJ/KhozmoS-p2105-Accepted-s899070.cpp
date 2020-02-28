#include<bits/stdc++.h>
#define MAXN 1007
using namespace std;
int n , m ,cont;
char isla[MAXN][MAXN];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m;
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < m ; j++)
        {
            cin>>isla[i][j];
        }
    }
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < m ; j++)
        {
            if(isla[i][j] == '+' && (i == 0 || i == n - 1 || j == 0 || j == m - 1))
                cont++;
            else if(isla[i][j] == '+' && isla[i - 1][j] == '+' && isla[i][j + 1] == '+' && isla[i + 1][j] == '+' && isla[i][j -1] == '+')
                continue;
            else if(isla[i][j] == '+')
                cont++;
        }
    }
    cout<<cont<<"\n";
    return 0;
}
