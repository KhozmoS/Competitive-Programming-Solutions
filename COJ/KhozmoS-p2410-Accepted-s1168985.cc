#include <stdio.h>

using namespace std;

int t, a, n;

int main() {
    scanf("%d", &t);
    for(int i = 1; i <= t; i++) {
        scanf("%d %d", &a, &n);
        printf("Case #%d: %.2lf\n", i, (double)(a * a) / (double)(1 << (n - 1)) + 1e-6);
    }
}
