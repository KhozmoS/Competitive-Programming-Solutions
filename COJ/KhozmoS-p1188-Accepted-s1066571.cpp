#include <bits/stdc++.h>

using namespace std;

const int MAXN = 11111;

int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int a , b;
    cin>>a>>b;

    int sum = 0;
     int sol = 0;
     while(b != 0){
      sum += b % 10 ; b /= 10;
     }
      while(a != 0){
      sol += (sum * (a % 10)) ; a /= 10;
      }
     cout<<sol<<"\n";
    return 0;
}
