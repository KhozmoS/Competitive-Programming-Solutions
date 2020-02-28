#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000;
int t;
const int MAX = 3000;
bool mk[MAX];
int ar[MAX];
int freq[MAX];
int main()
{
   ios_base::sync_with_stdio(0);cin.tie(0);
   int n , x;
   cin>>n>>x;
   for(int i = 0 ; i < n ; i++) cin>>ar[i] , mk[ar[i]] = true , freq[ar[i]]++;

   for(int i = 0 ; i < n ; i++)
   {
      if(freq[ar[i]] == 1)
      mk[ar[i]] = false;
      freq[ar[i]]--;
      for(int j = i + 1 ; j < n ; j++)
      {
         if(freq[ar[j]] == 1) mk[ar[j]] = false;

         if(mk[ar[i] ^ ar[j] ^ x]) {cout<<"YES\n"; return 0;}

         mk[ar[j]] = true;
      }
   }
   cout<<"NO\n";
   return 0;
}
