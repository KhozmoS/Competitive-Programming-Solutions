#include<bits/stdc++.h>


using namespace std;
const int MAX = 1e6 + 5;

int ar[20];
bool mk[MAX * 20];

int main()
{
  int n;
cin>>n;

 for(int i = 0 ; i < n ; i++) cin>>ar[i];

  for(int i = 0 ; i < (1 << n) ; i++)
  {
    int sum  = 0;
    for(int j = 0 ; j < n ; j++)
     if(i & (1 << j))
       sum += ar[j]; 
    mk[sum] = true;
  }
 int q; cin>>q;
while(q--)
{
  int x; cin>>x;
  if(mk[x]) cout<<"YES\n";
  else cout<<"NO\n";

}

}