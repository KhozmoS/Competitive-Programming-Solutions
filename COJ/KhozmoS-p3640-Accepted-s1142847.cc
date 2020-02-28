#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e5 + 5;
typedef long long ll;
typedef pair <int , int> par;
map <int , bool> mk;
long long ci = 0 , cp = 0;

int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int q;cin>>q;

   while(q--)
   {
     char t; cin>>t;

     if(t == 'q')
     {
        long long dos = 0 , tres = 0;
        if(cp >= 3)
           dos = (cp * (cp - 1ll) * (cp - 2ll)) / 6ll;
        if(ci >= 2){
           tres = (ci * (ci - 1ll)) / 2ll;
           tres *= cp;
           }
       cout<<tres + dos<<"\n";
     }
     if(t == 'i')
    {
       int x; cin>>x;
       if(mk[x]) continue;

       mk[x] = true;
       if(x % 2) ci++;
       else cp++;
     }
     if(t == 'r')
       {
         int x; cin>>x;
         if(!mk[x]) continue;
         mk[x] = false;
         if(x % 2) ci--;
         else cp--;

         if(cp < 0) cp = 0;
         if(ci < 0) ci = 0;
       }
   }
}
