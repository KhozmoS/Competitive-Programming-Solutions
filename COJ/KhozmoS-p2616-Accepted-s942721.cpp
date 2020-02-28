#include <bits/stdc++.h>


using namespace std;
const int MAXN = 100005;

int mon[] = { 1 , 3 , 5 , 6};
int men[MAXN];
int main()
{
       men[0] = 0;
       for(int i = 0 ; i < 4 ; i++) men[mon[i]] = 1;

     for(int i = 1 ; i < MAXN ; i++){
         men[i] = 1000000;
     for(int k = 0 ; k < 4 ; k++)
     {
         if(mon[k] <= i)
         {
             men[i] = min(1 + men[i - mon[k]] , men[i]);
         }
     }
     }
     int k; cin>>k;

     for(int t = 1 ; t <= k ; t++)
     {
         int q;
         cin>>q;
         cout<<"Case "<<t<<": "<<men[q]<<"\n";
     }
    return 0;
}
