#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1000007;

bool mk[MAXN];

int main(){

    //freopen(".in", "r", stdin);
    ios_base::sync_with_stdio(0);cin.tie(0);

    int n, sol = 1;
    while(cin >> n)
    {
        for(int i = 2; i *i <= n; i++)
            if(n % i == 0)
            {
                if(mk[i])sol = max(sol, i);
                if(mk[n / i])sol = max(sol, n / i);
                mk[i] = true;
                mk[n / i] =  true;
            }
        if(mk[n])sol = max(sol, n);
        mk[n] = true;
    }
    cout << sol << "\n";



    return 0;
}
