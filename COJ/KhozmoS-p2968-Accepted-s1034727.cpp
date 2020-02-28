#include <bits/stdc++.h>

using namespace std;

int ar[10];

bool F(int sum1 , int sum2 , int pos)
{
    if(pos == 6)
        return sum1 == sum2;

    return F(sum1 , sum2 + ar[pos] , pos + 1) + F(sum1 + ar[pos] , sum2 , pos + 1);
}

int main()
{
   ios_base::sync_with_stdio(0);cin.tie(0);

   int t;
   cin>>t;
   while(t--)
   {
     for(int i = 0 ; i < 6 ; i++) cin>>ar[i];
     if(F(0 , 0 , 0))
        cout<<"Tobby puede cruzar\n";
     else
        cout<<"Tobby no puede cruzar\n";
   }


    return 0;
}
