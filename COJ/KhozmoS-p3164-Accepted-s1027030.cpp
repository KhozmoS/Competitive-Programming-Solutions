#include <bits/stdc++.h>

using namespace std;

const int MAXN = 111111;
const int MOD = 1000000007;
long long N;
long long mayx = -1000000009;
long long mayy = -1000000009;
long long menx = 1000000009;
long long meny = 1000000009;

int main()
{
   ios_base::sync_with_stdio(0);cin.tie(0);
   cin>>N;
   for(int i = 0 ; i < N ; i++)
   {
     long long x , y;
     cin>>x>>y;
     if(x > mayx)
     mayx = x;

     if(x < menx)
     menx = x;

     if(y > mayy)
     mayy = y;

     if(y < meny)
     meny = y;
   }
      if(meny < 0 && mayy < 0){
            meny *= -1;
            mayy *= -1;
      }

      if(menx < 0 && mayx < 0){
       menx *= -1;
       mayx *= -1;
      }

      long long sol = max(abs(mayy - meny) , abs(mayx - menx) );
     cout<<(long long)(sol * sol)<<"\n";

    return 0;
}
