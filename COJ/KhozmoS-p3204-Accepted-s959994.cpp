#include <bits/stdc++.h>

using namespace std;
const int MAXN = 105;


int MAT[MAXN][MAXN];

int a , b , nod , arist;

int main()
{
    //ios_base::sync_with_stdio(0);cin.tie(0);

    while(cin>>nod>>arist)
{
    while(arist--)
    {
        cin>>a>>b;
        MAT[a][b]++;
        MAT[b][a]++;
    }
    bool flag = false;
    for(int i = 1 ; i <= nod ; i++ )
    for(int j = 1 ; j <= nod ; j++ )
    {
        if(MAT[i][j] == 0 && j != i)
        flag = true;
    }
    if(flag) cout<<"Yes\n";

    else cout<<"No\n";
    for(int i = 1 ; i <= nod ; i++ )
    for(int j = 1 ; j <= nod ; j++ )
    {
     MAT[i][j] = 0;
    }
  }
    return 0;
}
