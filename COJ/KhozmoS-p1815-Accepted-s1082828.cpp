#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ll;
#define f first
#define s second
typedef pair <int , int > par;
typedef pair <int , par> trio;

const int MAX = 1e6 + 5;
int ar[25];
int n;
map <int , bool> mk;

void F(int pos , int sum)
{
  mk[sum] = true;

  if(pos == n)
        return;

  F(pos + 1 , sum + ar[pos]);
  F(pos + 1 , sum);
}

int main()
{
   ios_base::sync_with_stdio(0);cin.tie(0);
   cin>>n;
   for(int i = 0 ; i < n ; i++)
       cin>>ar[i];
   F(0 , 0);
   int q;
   cin>>q;
   while(q--)
   {
       int x;
       cin>>x;
       (mk[x] ? cout<<"YES\n" : cout<<"NO\n");
   }

    return 0;
}
