#include <bits/stdc++.h>

using namespace std;
const int MAXN = 1111111;


int elef[MAXN];

int t , n , p;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>t;

  while(t--)
 {
   cin>>n>>p;
   for(int i = 0 ; i < n ; i++)
   {
      cin>>elef[i];
   }
    sort(elef , elef + n);
    int sum = 0;
    int sol = 0;
    for(int i = 0 ; i < n ; i++)
    {
       sum += elef[i];
       if(sum > p)
       break;

       else sol++;
    }
    cout<<sol<<"\n";
 }




    return 0;
}
