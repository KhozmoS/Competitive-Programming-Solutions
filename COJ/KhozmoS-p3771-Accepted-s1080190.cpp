#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
ios_base::sync_with_stdio(0);cin.tie(0);

  int t;
  cin>>t;

    while(t--){

       ll n , k;
       cin >> n >> k;
       int sol = 0;
       for(ll i = 1 ; i * i <= n ; i++)
       {
        if(n % i == 0)
        {
         if(i != n / i)   
         sol += (__gcd(i , k) == 1);
         sol += (__gcd(n / i , k) == 1);
        }
       }
        cout<<sol<<"\n";
    }


	return 0;
}
