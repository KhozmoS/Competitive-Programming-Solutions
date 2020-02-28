#include<bits/stdc++.h>


using namespace std;
const int MAXN = 1000005;
typedef long long LL;
int A[MAXN];
int TA[MAXN];

int find_center(LL n)
{
  LL ret = -1;
  LL sum1 = (n * (n + 1)) / 2;
  LL nn = n + 2;
  LL sum2 = 0;
  LL ind = n + 1;
  LL ini = ind; LL fin = MAXN;
  while(fin - ini >= 3)
  {
   LL mit = (fin + ini) / 2;
   sum2 = ((mit * (mit + 1)) / 2) - ((ind * (ind + 1)) / 2);
   if(sum2 > sum1)
   fin = mit;
   if(sum2 < sum1)
   ini = mit;
   if(sum2 == sum1)
   return mit;
  }
  for(LL i = fin; i > ini - 2 ; i--)
  {
    sum2 = ((i * (i + 1)) / 2) - ((ind * (ind + 1)) / 2);
    if(sum2 == sum1)
    return i;
  }
  return -1;
}
void tabla()
{
   for(LL i = 1 ; i < MAXN ; i++)
   {
       int ind = find_center(i);
       A[ind]++;
   }
   for(int i = 1 ; i < MAXN ; i++)
   TA[i] = A[i] + TA[i - 1];
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  tabla();
  int n;
  while(cin>>n && n)
  {
      cout<<TA[n]<<"\n";
  }
  return 0;
}
