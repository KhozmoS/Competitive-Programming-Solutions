#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll mod = 1e9 + 7;
ll B = 311;
ll HA[1000005] , POT[1000005];
string ar[5];
int per[] = {1 , 2 , 3};
int N;
int main()
{
   ios_base::sync_with_stdio(0);cin.tie(0);int ans = 1e9;
   cin>>ar[1]>>ar[2]>>ar[3];
   do{
   string cur = ar[per[0]];
   for(int i = 1 ; i < 3 ; i++)
   {
       string cad;
       cad = ar[per[i]];
       int sz1 = cur.size();
       int sz2 = cad.size();
       bool ok = false;
       if(sz1 > sz2)
       {
           POT[0] = 1;
           for(int i = 0 ; i < sz1 ; i++)
           {
               POT[i+1] = (POT[i] * B) % mod;
               HA[i+1] = (HA[i] * B % mod + (cur[i]-'a'))%mod;
           }
           ll H = 0;
           for(int i = 0 ; i < sz2 ; i++)
           {
               H = (H * B % mod + (cad[i]-'a')) % mod;
           }
           for(int i = sz2-1 ; i < sz1 ; i++)
           {
               ll H1 = (HA[i+1] - (HA[i+1-sz2] * POT[sz2])%mod + mod)%mod;
               if(H1==H)ok = true;
           }
       }
       if(ok) continue;
       int id1 = 0;
       int id2 = cur.size()-1;

       ll H1 = 0, H2 = 0;
       ll P = 1;int idd1 = 0;
       while(id1 < cad.size() && id2 > -1)
       {
           H1 = (H1 * B + cad[id1]) % mod;
           H2 = (cur[id2] * P + H2) % mod;
           if(H1 == H2)
           {
               idd1 = id1+1;
           }
           P = (P * B)%mod;
           id1++;
           id2--;
       }
       while(idd1 < cad.size())
           cur += cad[idd1++];

   }
   ans = min(ans , (int)cur.size());
   }while(next_permutation(per , per + 3));
    cout<<ans<<"\n";
}
