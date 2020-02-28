#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second

typedef long long ll;

typedef pair <int , int> par;

const int MAX = 1e2 +5;
const ll mod = 1e9 + 7;

int ar[MAX][MAX];

int r , c;
int ver(int x , int y)
{
    int res = 0;
    //arriba
    int i = x - 1;
    bool flag = false;
    while(i > 0)
    {
        if(ar[x][y] <= ar[i][y])
            flag = true;
        i--;
    }
    if(!flag) res++;
    //abajo
    i = x + 1;
     flag = false;
    while(i <= r)
    {
        if(ar[x][y] <= ar[i][y])
            flag = true;
        i++;
    }
    if(!flag) res++;
    //iz
    i = y - 1;
     flag = false;
    while(i > 0)
    {
        if(ar[x][y] <= ar[x][i])
            flag = true;
        i--;
    }
    if(!flag) res++;
    //der
     i = y + 1;
     flag = false;
    while(i <= c)
    {
        if(ar[x][y] <= ar[x][i])
            flag = true;
        i++;
    }
    if(!flag) res++;

    return res;
}
int main()
{
   ios_base::sync_with_stdio(0);cin.tie(0);



   cin>>r>>c;

   for(int i = 1 ; i <= r ; i++)
     for(int j = 1 ; j <= c ; j++)
       cin>>ar[i][j];
       int ans = 0;
   for(int i = 1 ; i <= r ; i++)
     for(int j = 1 ; j <= c ; j++)
     {
        int cont = ver(i , j);
        ans += cont;
     }
     cout<<ans<<"\n";
}
