#include<bits/stdc++.h>
#define MAXN 2018
using namespace std;

int AB[MAXN];
int A[MAXN];
int a , v;
 void update(int pos , int val)
 {
     for(int i = pos ; i < MAXN ; i += (i & -i))
        AB[i] += val;
 }
 int quare(int a , int b)
 {
     int suma = 0;
     int sumb = 0;
     a--;
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
 int menv = 305;
 int sola , solb , solc;
int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
 int t;
 cin>>t;
 int mena = 2015;
 int maya = 0;
   while(t--)
   {
      cin>>a>>v;
      A[a] = v;
      update(a , v);
      if(a < mena)
        mena = a;
      if(a > maya)
        maya = a;
   }
    for(int i = mena; i + 2 <= maya ; i++){
        if(A[i] != 0 && A[i + 1] != 0 && A[i + 2] != 0)
        {
            int c = quare(i , i + 2);
            if(menv >= c)
            {
              menv = c;
              sola = i; solb = i + 1; solc = i + 2;
            }
        }


    }
    cout<<sola<<" "<<solb<<" "<<solc<<"\n";
return 0;
}
