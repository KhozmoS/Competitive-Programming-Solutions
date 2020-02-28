#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAX  = 1000005;
const ll  mod  = 1000000007;

ll dp[MAX];

int n;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);

    dp[2] = 1;

    for(int i = 3 ; i < MAX - 3 ; i++)
        dp[i] = (1 + dp[i-1] * (i-2)) % mod;

    while(cin>>n){
        cout<<dp[n]<<"\n";
    }
}
