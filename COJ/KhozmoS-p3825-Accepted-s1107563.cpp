#include <bits/stdc++.h>

using namespace std;
int q , a , b;
int n , x;
const int MAX = 500005;
int ar[MAX];
int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0);
  while(cin>>n>>x){
   for(int i = 1 ; i <= n ; i++) ar[i] = i;


   int cant = n;
   int ans2 = 1;
   int p = 1;
   int cont = 0;
   while(cant != 1)
   {
       cont++;
       //cout<<ar[1]<<" "<<p<<"\n";
       int pos = 1;
       for(int i = 1 ; i <= cant ; i += 2)
       {

           if(ar[i] == x){
             ans2 = p;
           }

           if(i != cant)
           ar[pos++] = ar[i + 1];

       }
       p++;
       cant = pos - 1;
   }
   cout<<p<<" "<<ar[cant]<<" "<<ans2<<"\n";
}
    return 0;
}
