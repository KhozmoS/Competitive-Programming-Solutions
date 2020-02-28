#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 7;
const int MOD = 1000000007;

int dp[MAXN][100];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	int m, n;
	cin >> m >> n;

	string P, S;
	cin >> P >> S;

	dp[n][0] = 1;
	for (int i = n - 1; i >= 0; --i)
	{
		dp[i][0] = 1;
		for (int j = 1; j <= m; ++j)
		{
			if (S[i] == P[m - j])
                dp[i][j] = dp[i + 1][j - 1];

			dp[i][j] = (dp[i][j] + dp[i + 1][j]) % MOD;
		}
	}
	cout << dp[0][m] << endl;

	return 0;
}
