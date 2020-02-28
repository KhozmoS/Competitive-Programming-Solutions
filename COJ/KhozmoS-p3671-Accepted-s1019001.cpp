#include <bits/stdc++.h>

using namespace std;
const int MAXN = 1111111;
int cont = 1;

int main()
{

   ios_base::sync_with_stdio(0);cin.tie(0);
   long long n;

   cin>>n;
     if(n == 1) cout<<"0\n";

     else{
     while(n > 3)
     {
      int sum = n % 3;
      n /= 3;
      n += sum;
      cont++;
     }
     cout<<cont<<"\n";
     }
     return 0;
}
