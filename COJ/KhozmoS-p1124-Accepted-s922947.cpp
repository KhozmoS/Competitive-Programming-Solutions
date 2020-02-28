#include<bits/stdc++.h>
#define MAXN 1000000
using namespace std;
int prime[MAXN];
vector<int>vc;
bool is_prime(int n )
{
    if(n == 2)
    return true;
    if(n % 2 == 0)
    return false;
    for(int i = 3 ; i * i <= n ; i += 2)
    if(n % i == 0)
    return false;
    return true;
}
void tabla()
{
    for(int i = 3 ; i <= MAXN ; i++)
    if(is_prime(i))
    vc.push_back(i);
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    tabla();
    //int ta = vc.size();
    while(true)
    {
        bool flag = false;
        cin>>n;
        if(!n)
        break;
         int i = 0;
         while(vc[i] + vc[i] <= n)
         {
           int sola , solb;
           if(is_prime(n - vc[i]))
           {
               sola = vc[i];
               solb = n - vc[i];
               cout<<n<<" = "<<sola<<" + "<<solb<<"\n";
               flag = true;
               break;
           }
           i++;
         }
         if(!flag)
         cout<<"Goldbach's conjecture is wrong.\n";
    }
    return 0;
}
