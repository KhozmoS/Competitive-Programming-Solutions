#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int MAXN = 1e6 + 7;

LL A[MAXN];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int N;
    cin >> N;
    for(int i = 0; i < N; i++)
        cin >> A[i];

    sort(A, A + N);
    int i = 0, j = N - 1;

    LL sol = 1e18;
    while(i < j)
    {
        if(A[i] + A[j] < sol)
            sol = A[i] + A[j];
        //cout << i << " " << j <<  " " << A[i] + A[j] <<  endl;
        i++, j--;
    }
    cout << sol << "\n";

    return 0;
}
