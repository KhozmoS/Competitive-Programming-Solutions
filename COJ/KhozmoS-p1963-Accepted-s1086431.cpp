#include <bits/stdc++.h>

using namespace std;

const int MAXN = 21;

int n, sol;
int ar[MAXN];


bool ok(int i, int j){
    while(j && i){
        if((i % 10) + (j % 10) > 9)
            return 0;
        i /= 10;
        j /= 10;
    }

    return 1;
}

void F(int pos, int sum, int can){
    if(can > sol)
        sol = can;

    if(pos >= n || can + n - pos <= sol)
        return;

    if(ok(sum, ar[pos]))
        F(pos + 1, sum + ar[pos], can + 1);

    F(pos + 1, sum, can);
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n;

    for(int i = 0 ; i < n ; i++)
        cin >> ar[i];

    F(0, 0, 0);

    cout << sol << "\n";

    return 0;
}
