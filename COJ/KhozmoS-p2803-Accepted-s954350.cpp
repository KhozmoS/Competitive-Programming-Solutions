#include <bits/stdc++.h>
#define MAXN 15

using namespace std;

 int t , N;
 int mx[] = {0 , 1 , 0 , -1};
 int my[] = {1 , 0 , -1 , 0};

 char ar[MAXN][MAXN];

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);

  cin>>t;

  while(t--)
  {
    cin>>N;

    for(int i = 1 ; i <= N ; i++)
    for(int j = 1 ; j <= N ; j++)
    {
       cin>>ar[i][j];
    }
     bool flag = false;
    for(int i = 1 ; i <= N ; i++)
    for(int j = 1 ; j <= N ; j++)
    {
        for(int k = 0 ; k < 4 ; k++)
        if(ar[i][j] == ar[i + mx[k]][j + my[k]])
        flag = true;
    }
    if(flag) cout<<"NO\n";

    else cout<<"YES\n";
    //LIMPIAR
    for(int i = 0 ; i <= N ; i++)
    for(int j = 0 ; j <= N ; j++)
    ar[i][j] = '.';
  }

    return 0;
}
