#include <bits/stdc++.h>

using namespace std;
  int N;
  string name,sol;
  double pa,pj,g,a,ta,tr,comp;
   double mayor = -10000000;
int main()
{
    cin>>N;
    for(int i = 0;i < N; i++){
      cin>>name>>pa>>pj>>g>>a>>ta>>tr;
        comp =  log10(pa) + pj + (2 * g) + a -(ta + (2 * tr));
      if(mayor < comp ){
         mayor = comp;
         sol = name;
         }
    }

      cout<<sol<<endl;
    return 0;
}
