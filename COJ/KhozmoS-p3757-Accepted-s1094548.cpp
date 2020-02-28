#include<bits/stdc++.h>

using namespace std;
const int MAX = 36 * 36;

int ansp , ansi;
int t , n;

int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   cin>>t;
   while(t--)
   {
       cin>>n;
       ansp  = 0;
       ansi = 0;
       for(int i = 1 ; i * i <= n ; i++)
       {
           if(i * i != n && n % i == 0){
             ansp += ((n / i) % 2 == 0);
             ansi += ((n / i) % 2 == 1);
           }
           if(n % i == 0)
            ansp += ((i) % 2 == 0), ansi += ((i) % 2 == 1);
       }

       cout<<"P: "<<ansp<<" I: "<<ansi<<"\n";
   }
    return 0;
}
