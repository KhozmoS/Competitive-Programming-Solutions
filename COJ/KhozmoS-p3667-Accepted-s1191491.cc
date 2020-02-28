#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll mod = 1e9 + 7;
ll B = 311;

int N;
int main()
{
   ios_base::sync_with_stdio(0);cin.tie(0);
   cin>>N;
   string cur;
   N--;
   cin>>cur;
   while(N--)
   {
       string cad;
       cin>>cad;
       int id1 = 0;
       int id2 = cur.size()-1;
       ll H1 = 0, H2 = 0;
       ll P = 1;int idd1 = 0;;
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
   cout<<cur<<"\n";
}
