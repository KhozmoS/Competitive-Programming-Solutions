#include <bits/stdc++.h>

using namespace std;

const int MAXN = 11111;

int ar[MAXN];
int br[MAXN];
void prec()
{
 int ver = 1;
  for(int i = 1 ; i < MAXN ; i++)
  {
    ver++;
    if(ver == 3)
    {
      ar[i] = ar[i - 1] + 3;
      ver = 1;
    }
    else
       ar[i] = ar[i - 1] + 1;
  }
  ver = 1;
  br[2] = 2;
  for(int i = 3 ; i < MAXN ; i++)
  {
    ver++;
    if(ver == 3)
    {
      br[i] = br[i - 1] + 3;
      ver = 1;
    }
    else
       br[i] = br[i - 1] + 1;
  }
}

int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);

  prec();

   int t; cin>>t;
   while(t--)
   {
     int a , b; cin>>a>>b;
     if(a != b && a - 2 != b)
        cout<<"No Number\n";
     else if(a == b)
        cout<<ar[a]<<"\n";
     else
        cout<<br[a]<<"\n";

   }
    return 0;
}
