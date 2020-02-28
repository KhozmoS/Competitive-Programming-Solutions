#include <bits/stdc++.h>

using namespace std;


typedef long long ll;
int n;

ll A[11];
ll B[11];

int main()
{
   ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n;

     for(int i = 1 ; i <= n ; i++) cin>>A[i];

     for(int i = 1 ; i <= n ; i++) cin>>B[i];

     ll sum = 11111111111111111;
         
          sort(B + 1, B + n + 1);
          
     do{
        ll s = 0;
        for(int i = 1 ; i <= n ; i++)
        {
           s += (A[i] * B[i]);
        }
        
        if(s < sum)
            sum = s;

     }while(next_permutation(B + 1 , B + n + 1));

     cout<<sum<<"\n";

    return 0;
}
