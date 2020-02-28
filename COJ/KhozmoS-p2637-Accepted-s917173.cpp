#include <bits/stdc++.h>
#define MAXN 100005
using namespace std;
typedef long long LL;
LL AB[MAXN];
int t , n , q , x;
 void update(int pos , int val)
 {

     for(int i = pos ; i <= n ; i += (i & -i))
     {
         AB[i] += val;
     }

 }
  void limpAB()
  {
      for(int i = 1 ; i <= n ; i += (i & -i))
        AB[i] *= 0;
  }
 LL sum (int a , int b)
 {
     LL suma = 0;
     LL sumb = 0;
      for(int i = a ; i > 0 ; i -= (i & -i))
      {
        suma += AB[i];
      }
      for(int i = b ; i > 0 ; i -= (i & -i))
       {
        sumb += AB[i];
       }
      return sumb - suma;
 }
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>t;
    while(t)
    {
       cin>>n>>q;
       for(int i = 1 ; i <= n ; i++)
       {
          cin>>x;
          update(i , x);
       }
     while(q--)
     {
         int a , b;
         cin>>a>>b;
         cout<<sum(a , b + 1)<<"\n";
     }
     if(t > 1){
     cout<<"\n";
     //cout<<"\n";
     }
    for(int i = 1 ; i <= n ; i++)
    AB[i] = 0;
    t--;
    }
    //LIMPIAR
   // limpAB();
    return 0;
}
