#include<bits/stdc++.h>

 using namespace std;
    const int MAX=11;
    int Arr[MAX];
  int revers(int n){
   int numb = 0;
   int mult = 1;
     int p = n;
      while(p != 0){
        p /= 10;
        mult *= 10;
      }
   while(n>0){
      mult /= 10;
      numb +=  ( n % 10 ) * mult;
      n /= 10;
      }
    return numb;
  }
 int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  int a,b;
  cin>>n;
    for(int i=0;i<n;i++){
      cin>>a>>b;
      cout<<revers(revers(a) + revers(b))<<"\n";
    }

return 0;
}
