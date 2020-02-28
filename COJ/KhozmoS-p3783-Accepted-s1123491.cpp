#include <bits/stdc++.h>

using namespace std;



int F(int x)
{
    int sum = 0;
    for(int i = 1 ; i <= (int)sqrt(x) ; i++)
     if(x % i == 0)
     {
       if(x / i != i){
         sum += i ; sum += x / i;
       }
       else
         sum += i;
     }

     return sum;
}

const int MAX = 1e5 + 5;
int dp[MAX * 5];
int sum(int n , int k)
{
  int res = 0;

  for(int i = 1 ; i <= (int)sqrt(n) ; i++)
  {
      if(n % i == 0)
      {
          if(i % k == 0)
            res += i;

          if(i != (n / i) && (n / i) % k == 0)
            res += (n / i);
      }
  }

  return res;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t;
    cin>>t;
    for(int i = 1 ; i < MAX * 5 ; i++)
        dp[i] = F(i);

    while(t--)
    {
        int res = 0;
        int n , k;
        cin>>n>>k;

        if(k == 1)
        {
            cout<<"0\n";
            continue;
        }

        res += sum(n , k);

        cout<<dp[n] - res<<"\n";
    }


    return 0;
}
