#include <bits/stdc++.h>


using namespace std;

#define f first
#define s second

typedef long long ll;
typedef pair <int  , int > par;

const int mod = 1e9 + 7;
const int MAX = 1e6 + 5;

bool prime(int x)
{
   if(x == 2) return true;

   if(x % 2 == 0) return false;

   for(int i = 3 ; i * i <= x ; i += 2)
        if(x % i == 0)
         return false;

   return true;

}


int main()
{
    //cout<<__gcd(10 , 5);
    //cout<<prime(33);
   ios_base::sync_with_stdio(0);cin.tie(0);

    int n;
    cin>>n;
    int ans = 0;

    for(int i = 2 ; i <= n ; i++){
         int ver = __gcd(n , i);

        if(prime(ver) && ver != 1){
          ans++;
          //cout<<ver<<"\n";
        }
    }

    cout<<ans<<"\n";

    return 0;
}
