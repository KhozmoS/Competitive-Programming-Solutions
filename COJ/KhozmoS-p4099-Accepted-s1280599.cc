#include<bits/stdc++.h>


using namespace std;

int x[305] , n;
int y[305];

int distancia(int a , int b , int c, int d)
{
    int dx = (a-c)*(a-c);
    int dy = (b-d)*(b-d);
    return dx+dy;
}
bool colinear(int i , int j , int k)
{
    return (x[j]-x[i])*(y[k]-y[i])==(x[k]-x[i])*(y[j]-y[i]);
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    int ans = 0;
    for(int i = 1 ; i <= n ; i++)
        cin>>x[i]>>y[i];
    for(int i = 1 ; i <= n ; i++)
        for(int j = i+1 ; j <= n ; j++)
            for(int k = j+1 ; k <= n ; k++)
            {
                if(colinear(i , j , k)) continue;

                int ar[3];
                ar[0] = distancia(x[i] , y[i] , x[j] , y[j]);
                ar[1] = distancia(x[i] , y[i] , x[k] , y[k]);
                ar[2] = distancia(x[j] , y[j] , x[k] , y[k]);
                sort(ar , ar+3);
                if(ar[0]+ar[1]==ar[2])
                    ans++;
            }
   cout<<ans<<"\n";
}
