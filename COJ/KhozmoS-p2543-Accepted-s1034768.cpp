#include <bits/stdc++.h>

using namespace std;

int ar[20];
int n , k , p;


int F(int pos , int sum , int c)
{
    if(c == k && sum)
     return __gcd(sum , p) != 1;
    if(pos == n)
      return 0;

    return F(pos + 1 , sum , c) + F(pos + 1 , sum + ar[pos] , c + 1);
}

int main()
{
   ios_base::sync_with_stdio(0);cin.tie(0);


    while(cin>>n>>k>>p){
    for(int i = 0 ; i < n ; i++) cin>>ar[i];
    cout<<F(0, 0 , 0)<<"\n";
    }


    return 0;
}
