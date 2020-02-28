#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second

typedef long long ll;

typedef pair <int , int> par;

const int MAX = 1e2 +5;
const ll mod = 1e9 + 7;


int main()
{
   ios_base::sync_with_stdio(0);cin.tie(0);

   ll a , b , a1 , b1;
   cin>>a>>b>>a1>>b1;

   if(a > b) swap(a , b);
   if(a1 > b1) swap(a1 , b1);

   if(a < a1 || b < b1){cout<<"-1\n"; return 0;}
   ll ans = 0;
   if(a == a1 && b == b1){cout<<"0\n" ; return 0;}
   if(a > b1) swap(a , b);
   ll r = a; ll c = b;
   while(a != a1)
   {
       if(!(a & 1)){
       if((a >> 1) > a1){
           a >>= 1;
           ans++;
       }
         else{
           a = a1;
           ans++;
         }
       }
       else
       {
         if((a >> 1)+1ll > a1){
           a >>= 1;
           a++;
           ans++;
       }
         else{
           a = a1;ans++;
         }
       }

   }

   while(b != b1)
   {
       if(!(b & 1)){
       if((b >> 1) > b1){
           b >>= 1;
           ans++;
       }
         else{
           b = b1;
           ans++;
         }
       }
       else
       {
         if((b >> 1)+1ll > b1){
           b >>= 1;
           b++;
           ans++;
       }
         else{
           b = b1;
           ans++;
         }
       }

   }
   ll ans1 = ans;
   ans = 0;
   a = r; b = c;
   if(a > b) swap(a , b);
    while(a != a1)
   {
       if(!(a & 1)){
       if((a >> 1) > a1){
           a >>= 1;
           ans++;
       }
         else{
           a = a1;
           ans++;
         }
       }
       else
       {
         if((a >> 1)+1ll > a1){
           a >>= 1;
           a++;
           ans++;
       }
         else{
           a = a1;ans++;
         }
       }

   }

   while(b != b1)
   {
       if(!(b & 1)){
       if((b >> 1) > b1){
           b >>= 1;
           ans++;
       }
         else{
           b = b1;
           ans++;
         }
       }
       else
       {
         if((b >> 1)+1ll > b1){
           b >>= 1;
           b++;
           ans++;
       }
         else{
           b = b1;
           ans++;
         }
       }

   }
   cout<<min(ans , ans1)<<"\n";
}
