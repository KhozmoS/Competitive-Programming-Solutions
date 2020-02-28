#include<bits/stdc++.h>


using namespace std;

long long int dp[105][105];

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    cin>>n;
    while(n--)
    {
        int may = -1;
        int cantp = 1;
        int pis; cin>>pis;
        int esc = 1;
        for(int i = 1 ; i <= pis ; i++)
        {
            int k = 1;

            while(k <= cantp)
            {
                int x;
                cin>>x;
                dp[esc][k] = x + max(dp[esc - 1][k] , dp[esc - 1][k - 1]);
                if(may < dp[esc][k])
                may = dp[esc][k];
                k++;
            }
           cantp++;
           esc++;
        }

            cout<<may<<"\n";
            //Limpiar
            for(int i = 1 ; i <= pis ; i++)
            for(int j = 1 ; j <= i ; j++)
            dp[i][j] = 0;
    }

    return 0;
}
