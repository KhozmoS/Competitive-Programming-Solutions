#include<bits/stdc++.h>

using namespace::std;
typedef long long ll;
const ll oo = 1e18+1;
ll dp[205][213][200] ,  pw[205];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	pw[0] = 1ll;
	dp[0][0][0] = 1;
	int s,m,q;
	cin >> s>>m>>q;
	for(int i = 1 ; i <= 200 ; i++)
        pw[i] = (pw[i-1] * 10) % m;

    for(int i = 0 ; i <= 200 ; i++)
        for(int j = 0 ; j <= s ; j++)
            for(int k = 0 ; k < m ; k++)
                for(int d = 0 ; d < 10 ; d++){
                    int pref = (pw[i]*d)%m;
                    dp[i+1][j+d][(pref+k)%m] += dp[i][j][k];
                    dp[i+1][j+d][(pref+k)%m] = min(dp[i+1][j+d][(pref+k)%m] , oo);
                }
    //prep(m);
    while(q--)
    {
        ll k;cin>>k;
        int ns = s;
        int nr = 0;
        int i;
        for(i = 1 ; i <= 200 && dp[i][ns][nr] < k; i++);
        if(i>200)
        {
            cout<<"NIE\n";
            continue;
        }
        for(;i;i--)
            for(int d = 0 ; d < 10 ; d++)
            {
                int pref = (pw[i-1]*d)%m;
                if(dp[i-1][ns-d][(nr-pref+m)%m] >= k)
                {
                    cout<<d;
                    ns-=d;
                    nr = (nr-pref+m)%m;

                    break;
                }
                else k-=dp[i-1][ns-d][(nr-pref+m)%m];
            }
        cout<<"\n";
    }
	return 0;
}
