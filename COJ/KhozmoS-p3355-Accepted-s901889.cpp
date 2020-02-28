#include <bits/stdc++.h>
#define MAXN 3005
using namespace std;
int TA[MAXN];
bool is_prime(int a)
{
    if(a == 2)
      return true;
    if(a % 2 == 0)
      return false;
    for(int i = 3 ; i * i <= a ; i += 2)
        if(a % i == 0)
        return false;
    return true;
}
int cont;
void tabla()
{
    for(int i = 6 ; i < MAXN ; i++)
    {
      for(int j = 2 ; j < i ; j++)
      {
          if(i % j == 0)
          {
            if(is_prime(j))
                cont++;
          }
      }
       if(cont == 2)
         TA[i] = TA[i - 1] + 1;

        else
         TA[i] = TA[i - 1];
        cont = 0;
    }

}
int n;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    tabla();
    cin>>n;
    cout<<TA[n]<<"\n";
    return 0;
}
