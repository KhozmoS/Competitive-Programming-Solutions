#include <bits/stdc++.h>
//KmS_Joel...
using namespace std;
 int n , m , d;
int main()
{
     ios_base::sync_with_stdio(0);cin.tie(0);
     cin>>n;
     while( n-- )
     {
       cin>>m>>d;
       if(m == 1)
       cout<<0<<"\n";
       else
       {
        int V = d / m;
        V = d - V;
        cout<< V <<"\n";
       }
     }
     /*int c1 = 1;
     int c2 = 67;
    for(int i = 1 ; i <= 33 ; i++)
    {
      c1 += 3;
      c2 += 1;
    }
     cout<<c1<<" "<<c2<<"\n";*/
    return 0;
}
