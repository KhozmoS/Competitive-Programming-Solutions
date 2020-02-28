#include <bits/stdc++.h>

using namespace std;
set <int> ans;
const int MAX = 1e5 + 5;
int ar[MAX];
bool mk[MAX][105];

int main() {
     ios_base::sync_with_stdio(0);cin.tie(0);
     int n;
     while(cin>>n && n)
     {
         for(int i = 0 ; i < n ; i++) cin>>ar[i];

         for(int i = 0 ; i < n ; i++)
         {
             int cur = ar[i];
             ans.insert(cur);

             for(int j = i+1 ; j < n ; j++)
             {
                 if(mk[j][cur]) break;
                 cur = __gcd(cur , ar[j]);
                 ans.insert(cur);
                 mk[j][cur] = true;
             }
         }
         cout<<ans.size()<<"\n";
         ans.clear();
         memset(mk , false ,sizeof(mk));
     }
}
