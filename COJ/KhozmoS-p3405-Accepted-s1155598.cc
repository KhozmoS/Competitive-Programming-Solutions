#include <bits/stdc++.h>

using namespace std;

char d[50];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> d;

    int N = atoi(d);
    int n = strlen(d);

    sort(d, d + n);
    
    
    do {
        for(int mask = (1 << (n - 1)) + 1; mask < (1 << n); mask++) {
            int prod = 1, last = 0;
            for(int i = 0; i < n; i++) {
                last = last * 10 + (d[i] - '0');
                if(mask & (1 << i)) {
                    prod *= last;
                    last = 0;
                }
                if(prod == N) {
                    cout << "YES\n";
                    return 0;
                }
            }
        }
    } while(next_permutation(d, d + n));

    cout << "NO\n";           
}
