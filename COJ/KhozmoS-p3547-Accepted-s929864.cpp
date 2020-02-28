#include <bits/stdc++.h>

using namespace std;
 const int MAXN = 1005;

 int MA[MAXN][MAXN];
 int TA[MAXN][MAXN];
 int R , C , Q;
 int x1 , x2 ;int y , y2;

int main()
{
    int a;
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>R>>C>>Q;
    for(int i = 1 ; i <= R ; i++){
    for(int j = 1 ; j <= C ; j++){
        cin>>a;
    if(a >= 0){
    MA[i][j] = a;
    TA[i][j] = ((TA[i - 1][j] + TA[i][j - 1]) - TA[i - 1][j - 1]) + MA[i][j];
    }
    else
    TA[i][j] = ((TA[i - 1][j] + TA[i][j - 1]) - TA[i - 1][j - 1]) + MA[i][j];
    }
    }
    while(Q--)
    {
        cin>>x1>>y>>x2>>y2;
        cout<<((TA[x2][y2] - TA[x1 - 1][y2]) - TA[x2][y - 1]) + TA[x1 - 1][y - 1]<<"\n";
    }
    return 0;
}
//Busklaxd
