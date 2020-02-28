#include <bits/stdc++.h>

using namespace std;
const int MAXN = 5000000;
const int MOD = 26;
vector <int> imp;
void tabla()
{
    for(int i = 1 ; i <= MAXN ; i += 2)
    imp.push_back(i);
}
//1 2 3 4
//4 3 2 1
  // n ( n * 2 ) / 2

//1 3 5 7 9
//9 7 5 3 1
bool mk[MAXN];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
     //tabla();
     int n; int cont = 0;
     cin>>n;
     for(int i = 0 ; i < n ; i++)
     {
         int x;
         cin>>x;
         if(!mk[x] && x <= n)
         {
             mk[x] = true;
             cont++;
         }
     }
     cout<<n - cont<<"\n";
    return 0;
}
