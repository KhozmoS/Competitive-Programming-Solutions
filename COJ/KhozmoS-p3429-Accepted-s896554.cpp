#include<bits/stdc++.h>

using namespace std;
const int MAX = 500005;
const int MOD = 1000000007;
long long TA[MAX];
void tabla(){
  TA[0] = 0;
  TA[1] = 1;
   long long k = 3;
   for(int i = 2; i < MAX ;i ++){
     long long a = k * k;
     TA[i] = ((a%MOD) + (TA[i - 1] % MOD)) % MOD;
     k += 2;
     }
}
 int n;
int main ()
{
    tabla();

    while(scanf("%d",&n) != EOF){
     if(n % 2 == 1)
      printf("%d\n",TA[n / 2 + 1]);
      else
     printf("%d\n",TA[n / 2]);
    }
    return 0;
}
