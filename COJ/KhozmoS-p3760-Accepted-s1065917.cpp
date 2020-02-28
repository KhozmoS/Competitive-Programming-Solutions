#include <bits/stdc++.h>

using namespace std;

int a , b;

 bool check (int x , int y)
 {
   int sa = 1;

   for(int i = 2 ; i < x ; i++)
    if(x % i == 0)
     sa += i;
     if(sa == y)
     return true;

   int sb = 1;
   for(int i = 2 ; i < y ; i++)
    if(y % i == 0)
     sb += i;

    if(sb == x)
    return true;


 return false;
 }


int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
     cin>>a>>b;

     if(check( a , b))
       cout<<"YES\n";

       else
       cout<<"NO\n";

    }


    return 0;
}
