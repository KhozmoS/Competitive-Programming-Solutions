#include <bits/stdc++.h>
#define MAXN 2600

using namespace std;

int ar[MAXN];
int sol[MAXN];

void tabla()
{
    for(int i = 1 ; i < MAXN ; i++)
    {
        for(int j = 1 ; j <= i ; j++)
        if(i % j == 0)
        ar[i]++;
    }
    for(int i = 1 ; i < MAXN ; i++)
    {
        int may = -1;
        for(int j = i ; j > 0 ; j--)
        {
          if(may <= ar[j])
          {
            sol[i] = j;
            may = ar[j];
          }
        }
    }

}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
     tabla();
     int n;
     cin>>n;

     while(n--)
     {
         int x; cin>>x;

         cout<<sol[x]<<"\n";
     }


    return 0;
}
