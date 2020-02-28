#include <bits/stdc++.h>

using namespace std;
const int MAXN = 105;

int ar[MAXN];
bool mk[MAXN];
int n;
bool mrk[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
     int c , n;

     while(cin>>c>>n)
     {
       if(!c && !n) break;

       int f;   int vent = 0;
       for(int i = 0 ; i < n ; i++)
       {
           cin>>f;

           if(c - f >= 0)
           {
               c -= f;
               vent++;
           }
       }
       cout<<vent<<" "<<c<<"\n";
     }
    return 0;
}
