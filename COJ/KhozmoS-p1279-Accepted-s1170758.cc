//1279 - Fermat's Christmas GREATSHIT!!
//by KhozmoS

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int MAX = 1e6 + 6;
int AC[MAX] , ACP[MAX];
bool mk[MAX];
bool ya[MAX];
int main()
{
    //ios_base::sync_with_stdio(0);cin.tie(0);
   for(int i = 2; i * i < MAX ; i++)
       if(!mk[i])
         for(int j = i * i ; j < MAX ; j += i)
            mk[j] = true;
   //mk[0] = true;
   mk[1] = false;
   mk[2] = true;
   for(int i = 0 ; i < MAX && i * i < MAX; i++)
       for(int j = 0 ; j*j + i*i < MAX ; j++)
          if(!mk[j*j + i*i] && !ya[j*j + i*i]){
              AC[j*j + i*i]++;
              ya[j*j + i*i] = true;
          }

   for(int i = 1 ; i < MAX ; i++)
   {
       if(!mk[i]) ACP[i]++;

       ACP[i] += ACP[i-1];
       AC[i] += AC[i-1];
   }

   int lo , hi;
   while(cin>>lo>>hi){
       int real_lo = lo;
       int real_hi = hi;
       if(hi == -1 && lo == -1){return 0;}
       if(hi < 1) hi = 0;
       if(lo < 1) lo = 1;
       cout<<real_lo<<" "<<real_hi<<" "<<ACP[hi] - ACP[lo-1]<<" "<<AC[hi] - AC[lo-1]<<"\n";
   }

}
