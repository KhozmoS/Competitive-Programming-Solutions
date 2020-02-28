#include <bits/stdc++.h>

using namespace std;
const int mod = 1e9 + 7;
const int MAX = 1e6 + 5;
bool ans[MAX];
int main()
{
   int n,k;
   cin>>n>>k;
   while(k--)
   {
       int x;cin>>x;
       int i = x;
       while(i <= n)
       {
           ans[i] = true;
           i += x;
       }
   }int sol = 0;
   for(int i = 0; i <= n ; i++) sol += ans[i];
   cout<<sol<<"\n";
}
