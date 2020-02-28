#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

#define oo 1000000
#define max(a, b) ((a) > (b) ? (a) : (b))

bool mark[20];
int t, n, answ, dp[20];
string list[20];

vector <int> v[20];

int solve(int id) {
    if(dp[id])
        return dp[id];
        
    for(int i = 0; i < v[id].size(); i++) {
        int to = v[id][i];
        if(!mark[to]) {
            mark[to] = true;
            dp[id] = max(dp[id], solve(to) + list[id].length());
            mark[to] = false;
        }
    }
    
    return dp[id] ? dp[id] : dp[id] = list[id].length();
}

main() {
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        for(int i = 1; i <= n; i++) {
            cin >> list[i];
            v[i].clear();
        }
        
        answ = 0;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                if(i == j)continue;
                if(list[i][0] == list[j][list[j].length()-1])
                    v[j].push_back(i);
            }
        }
        
        for(int i = 1; i <= n; i++) {
            memset(dp, 0, sizeof(dp));
            mark[i] = true;
            answ = max(answ, solve(i));
            mark[i] = false;
        }
        
        printf("%d\n", answ);
    }
}