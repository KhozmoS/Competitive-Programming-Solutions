#include <bits/stdc++.h>
#define MAXN 1000004
using namespace std;
int A[MAXN];
int n;
int men = 1000000000;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n;
     for(int i = 0 ; i < n ; i++)
       cin>>A[i];
     for(int i = 0 ; i < n ; i++)
     {
      int fin;
      int ini = i;
      if(i == 0)
      fin = n - 1;
      else
      fin = ini - 1;
      int p = 0;
      int sol = 0;
       while(true)
       {
         if(ini == n)
         {
           ini = 0;
         }
         //cout<<ini<<" "<<fin<<"\n";
         sol += A[ini] * p;
         if(ini == fin)
         break;
         p++;
         ini++;
       }
       //cout<<"Ok\n";
       if(men > sol)
       men = sol;
     }
     cout<<men<<"\n";
    return 0;

}
