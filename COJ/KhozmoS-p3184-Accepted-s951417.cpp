#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

LL e , b , obj;

LL cd(LL base ,LL ep)
{
    return ((LL)(ep * log10(base))) + 1;
}


int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    //cout<<cd(2 , 9999999999)<<"\n";
     cin>>b>>obj;
     LL ini , fin , mit;
     ini = 1; fin = 999999999999;
     //cout<<log2(100000000000);
      while(fin - ini >= 5)
      {
          mit = (fin + ini) / 2;
          if(cd(b , mit) <= obj)
          {
             ini = mit;
          }
          else
          {
             fin = mit;
          }
      }
      LL sol;
      bool flag = false;
      for(LL i = ini ; i <= fin ; i++)
      {
          if(cd(b , i) == obj)
          {
              flag = true;
              for(LL j = i ; j >= -1 ; j --)
              {
                  if(cd(b , j) == obj - 1 || j == 0)
                  break;

                  sol = j;
              }
          }
          if(flag) break;
      }

      cout<<sol<<"\n";
    return 0;

}
