#include <bits/stdc++.h>
#define N 55
using namespace std;
int t;
long long TA[N];
bool is_prime(int a)
{
    if(a % 2 == 0)
        return false;
     if(a == 3)
       return true;
    for(int i = 3 ; i * i <= a ; i++)
    {
        if(a % i == 0)
            return false;
    }
    return true;
}
void tabla()
{
  TA[2] = 2;
   for(int i = 3 ; i <= N ; i++)
   {
       if(is_prime(i))
        TA[i] = i * TA[i - 1];
       else
        TA[i] = TA[i - 1];
   }

}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int a;
  tabla();
  cin>>t;
   while(t--)
   {
       cin>>a;
       cout<<TA[a]<<"\n";
   }
    return 0;
}
