#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e6 + 5;
const int mod = 1000000;

int n, ind1, ind2, ind3;
int dp[MAX];

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    dp[0] = 1;
    for(int i = 1; i < MAX; i++) {
        ind1 = i - sqrt(i);
        ind2 = log(i);
        ind3 = i * sin(i) * sin(i);
        dp[i] = (dp[ind1] + dp[ind2] + dp[ind3]) % mod;
    }
    
    
    while(cin>>n){ 
        if(n == -1) return 0;
        cout<<dp[n]<<"\n";
    }
    return 0;
}
