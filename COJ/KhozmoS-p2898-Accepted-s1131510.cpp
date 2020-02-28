#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>

using namespace std;

long long n, list[2005], last[2005], answ = 1, k, pos;

main() {
    scanf("%lld", &n);
    
    for(long long i = 1; i <= n; i++) {
        scanf("%lld", &list[i]);
        last[i] = 0;
    }
    
    last[1] = 1;
    for(long long i = 2; i <= n; i++) {
        k = 0;
        pos = i - 1;
        for(long long c = i - 1; c >= 1; c--) {
            k = max(k, last[c]);
            if(c < k) {
                last[i] = c + 1;
                break;
            }
            if(__gcd(list[i], list[c]) != 1) {
                last[i] = c + 1;
                break;
            }
            if(c == 1)
                last[i] = 1;
        }
        answ = max(answ, i - last[i] + 1);
    }
    
    printf("%lld\n", answ);
}