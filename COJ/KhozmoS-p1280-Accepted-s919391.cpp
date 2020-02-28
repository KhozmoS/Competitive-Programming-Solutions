#include<bits/stdc++.h>
#define MAXN 1005

using namespace std;
typedef long long LL;
LL TA[MAXN];
void pre()
{
    TA[1] = 1;
    int sum = 2;
    for(int i = 2 ; i < MAXN ; i++)
    {
        TA[i] = TA[i - 1] +  sum;
        sum += 2;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    pre();
    int t , n;
    while(cin>>t)
    {
      if(t == 0)
      break;
      cout<<t<<" => "<<TA[t]<<"\n";
    }

    return  0;
}
