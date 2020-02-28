#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>

using namespace std;

#define MAX 35

typedef vector <int> vi;

int n, dim, sol, dp[MAX], prev[MAX];
int list[MAX][15];

inline bool cmp(int *a, int *b) {
    for(int i = 0; i < dim; i++)
        if(a[i] >= b[i])
            return false;
    return true;
}

int main() {
    
    while(scanf("%d %d", &n, &dim) != EOF) {
        for(int i = 1; i <= n; i++) {
            for(int j = 0; j < dim; j++)
                scanf("%d", &list[i][j]);
            sort(list[i], list[i] + dim);
        }

        memset(dp, 0, sizeof(dp));
        memset(prev, -1, sizeof(prev));

        for(int k = 1; k <= n; k++)
            for(int i = 1; i <= n; i++)
                for(int j = 1; j <= n; j++) {
                    if(!cmp(list[i], list[j]) || i == j)continue;
                    if(dp[i] < dp[j] + 1)
                        dp[i] = dp[j] + 1, prev[i] = j;
                    else if(dp[i] == dp[j] + 1)
                        prev[i] = min(prev[i], j);
                }

        sol = 1;
        for(int i = 2; i <= n; i++)
            if(dp[sol] < dp[i])
                sol = i;

        printf("%d\n", dp[sol] + 1);

        while(prev[sol] != -1) {
            printf("%d ", sol);
            sol = prev[sol];
        }
        printf("%d\n", sol);
    }
}
