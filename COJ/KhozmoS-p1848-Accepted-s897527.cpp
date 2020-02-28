#include <bits/stdc++.h>

using namespace std;
 int A[10001];
 const int MOD=10000;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
   A[0]=1;
   A[1]=1;
    for(int i=2;i<10000;i++)
    {
       A[i]=((A[i-1] % MOD)+(A[i-2] % MOD))%MOD;
    }
      int n,a;
      cin>>n;
      for(int i=0;i<n;i++)
      {
        cin>>a;
        cout<<A[a-3]<<" "<<A[a-2]<<" "<<A[a-1]<<"\n";
      }


    return 0;
}
