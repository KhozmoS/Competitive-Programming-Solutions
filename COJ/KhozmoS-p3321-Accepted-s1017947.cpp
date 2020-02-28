#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
const LL MAXN = 1000005;
const LL MOD = 10000000000;
LL arr[MAXN];
bool mk[MAXN]; int t , n;
int c;
void criba()
{
    mk[1] = true;c++;
    for(int i = 4 ; i <= MAXN ; i += 2)
    mk[i] = true , c++;

    for(int i = 3 ; i * i <= MAXN ; i += 2)
    {
      if(!mk[i])
      {
        for(int j = i * i ; j <= MAXN ; j += (i + i))
        mk[j] = true;c++;
      }
    }
}
int flag;
void prec()
{
    bool bandera = false;
    arr[2] = 2;
    for(LL i = 3 ; i <= MAXN ; i++)
    {
        if(!mk[i])
        {
          if(!bandera && (arr[i - 1] * i) >= MOD)
          {
              bandera = true;
              flag = i;
          }
          arr[i] = (((arr[i - 1] % MOD) * (i % MOD))% MOD);
        }
        else
        arr[i] = arr[i - 1];
    }
}
 void imprime(LL pos)
 {
     LL x = arr[pos];
     int cont = 0;
     while(x != 0)
     {
         x /= 10;
         cont++;
     }
     if(cont == 0)
     cout<<"0000000000\n";
     else{

     for(int i = 0 ; i < 10 - cont ; i++)
     cout<<0;
     cout<<arr[pos]<<"\n";

     }
 }
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    criba();
    prec();
    c = 0;
    //for(int i = 1 ; i <= 1000 ; i++) if(!mk[i]) c++; cout<<c;
    /*for(int i = 1 ; i <= 11 ; i++)
    cout<<mk[i]<<"\n";*/
     cin>>t;
     while(t--)
     {
         cin>>n;
         if(n < flag)
         cout<<arr[n]<<"\n";
         else
         imprime(n);
     }
    return 0;
}
