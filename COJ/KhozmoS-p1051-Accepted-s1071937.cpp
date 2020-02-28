#include<bits/stdc++.h>
using namespace std;
int n , cont;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n;
   
       for(int i = 1 ; i <= n ; i += 3 )
       {
           cont++;   
       }

       cout<<n - cont<<"\n";
     

    return 0;
}
