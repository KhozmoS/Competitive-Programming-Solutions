#include<bits/stdc++.h>

using namespace std;



typedef long long ll;
ll P[75][75];

void PASCAL()
{

    for(int i = 0; i <= 74; i++)
    P[i][0] = P[i][i] = 1;

    for(int i = 1; i <= 74; i++)
      for(int j = 1; j < i; j++)
        P[i][j] = P[i - 1][j - 1] + P[i - 1][j];

}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);

    PASCAL();

    int t;
    cin >> t;
    while(t--)
    {

        int tes, n;

        cin>>tes>>n;

        cout<<tes<<" "<<P[n + 9][n]<<"\n";

    }

    return 0;
}
