#include <bits/stdc++.h>

using namespace std;

const int MAX = 40;
const int mod = 1e6;

int dp[10][MAX][MAX][MAX][4][4];
int A[8];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> A[0] >> A[1] >> A[2] >> A[3];

    if(A[1] + A[2] + A[3] + A[0] == 1) {
        cout << "1\n";
        return 0;
    }

    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++)
            if((A[i] && A[j] && i != j) || (i == j && A[i] >= 2))
                dp[(i == 0) + (j == 0)][(i == 1) + (j == 1)][(i == 2) + (j == 2)][(i == 3) + (j == 3)][i][j] =
                    dp[(i == 0) + (j == 0)][(i == 1) + (j == 1)][(i == 2) + (j == 2)][(i == 3) + (j == 3)][j][i] = 1;

    for(int i = 0; i <= A[0]; i++) {
        memset(dp[(i + 5) % 10], 0, sizeof dp[(i + 2) % 3]);

        for(int j = 0; j <= A[1]; j++)
            for(int k = 0; k <= A[2]; k++)
                for(int l = 0; l <= A[3]; l++) {
                    for(int a = 0; a < 4; a++) {
                        for(int b = 0; b < 4; b++) {
                            for(int c = 0; c < 4; c++) {
                                if(a < 2 && b < 2 && c < 2)
                                    continue;

                                if(a >= 2 && b >= 2 && c >= 2)
                                    continue;

                                if((a % 2) == (b % 2) && (b % 2) == (c % 2))
                                    continue;

                                if(i + (c == 0) > A[0])continue;

                                if(j + (c == 1) > A[1])continue;

                                if(k + (c == 2) > A[2])continue;

                                if(l + (c == 3) > A[3])continue;

                                int &aux = dp[(i + (c == 0)) % 10][j + (c == 1)][k + (c == 2)][l + (c == 3)][b][c];
                                aux = (aux + dp[i % 10][j][k][l][a][b]) % mod;
                            }
                        }
                    }
                }
    }

    int sol = 0;

    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++)
            sol = (sol + dp[A[0] % 10][A[1]][A[2]][A[3]][i][j]) % mod;

    cout << sol << '\n';

}