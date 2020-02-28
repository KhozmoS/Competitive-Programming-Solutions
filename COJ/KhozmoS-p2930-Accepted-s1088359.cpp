#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e3 + 5;
const int mod = 1e9 + 7;
int dp1[MAX] , dp2[MAX], ar[MAX] , n;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    while(cin>>n)
    {
       memset(dp1 , 0 , sizeof(dp1));
       memset(dp2 , 0 , sizeof(dp2));
       int cre = 0, dec = 0;
       for(int i = 0 ; i < n ; i++) cin>>ar[i];
       
       for(int i = 0 ; i < n ; i++)
           for(int j = i - 1 ; j >= 0 ; j--)
             if(ar[i] > ar[j]) dp1[i] = max(dp1[j] + 1, dp1[i]) , cre = max(cre , dp1[i]);
             else if(ar[i] < ar[j]) dp2[i] = max(dp2[j] + 1 , dp2[i]) , dec = max(dec , dp2[i]);

             if(cre == dec)
                cout<<"Caution. I will not intervene.\n";
             else
                cout<<"Don't worry. I must intervene.\n";
    }
    return 0;
}
