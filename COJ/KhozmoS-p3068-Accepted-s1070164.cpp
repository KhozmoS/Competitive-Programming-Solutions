#include<bits/stdc++.h>

using namespace std;

const int MAX = 1e5 + 11;

bool mk[MAX];
int ar[MAX]; int n;

int main()
{
 ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n;
  for(int i = 0 ; i < n ; i++){
    cin>>ar[i];
     mk[ar[i]] = true;
   }
 int q1 , q2;
 cin>>q1>>q2;
  while(q1--)
{
 int a;
  cin>>a;
  if(mk[a])
    cout<<":)\n";
else
    cout<<":(\n";

 }
sort(ar + 0 , ar + n);
while(q2--)
{
int a;
 cin>>a;
 cout<<ar[a - 1]<<"\n";
}
return 0;
}
