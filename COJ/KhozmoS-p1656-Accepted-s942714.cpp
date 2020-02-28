#include <algorithm>
#include <iostream>
#define MAXN 505
#define MAXH 45005
using namespace std;
int dp(int,int);
int DP[MAXH];
int weights[MAXN];
int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int h,n;
    cin >> h >> n;
    for(int i=0;i<n;i++) cin >> weights[i];
    for(int i=0;i<=h;i++)DP[i] = -1;
    cout << dp(n-1,h) << "\n";
    return 0;
}
int dp(int i,int h) {
    if (i < 0) return 0;
    if(weights[i] > h) return dp(i-1,h);
    if(DP[h] != -1) return DP[h];
    return DP[h] = max(dp(i-1,h),dp(i-1,h-weights[i]) + weights[i]);
}
