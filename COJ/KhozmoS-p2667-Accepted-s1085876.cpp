#include <bits/stdc++.h>

using namespace std;

bool flag;
set <int> sol;
int n, tmp, pos, best, lista[1005];

int main() {
    scanf("%d", &n);

    for(int i = 1; i <= n; i++)
        scanf("%d", &lista[i]);

    best = 0;
    for(int i = 1; i <= n; i++) {
        int lo = i - 1, hi = i + 1;
        while(lista[lo] % lista[i] != 0 && lo >= 1)
            lo--;
        while(lista[hi] % lista[i] != 0 && hi <= n)
            hi++;
        lo++, hi--;
        if(hi - lo + 1 > best) {
            sol.clear();
            sol.insert(lo);
            best = hi - lo + 1;
        }
        else if(hi - lo + 1 == best)
            sol.insert(lo);
    }

    printf("%d %d\n", best--, sol.size());
    for(set <int> :: iterator ite = sol.begin(); ite != sol.end(); ite++)
        printf("%d %d\n", *ite, *ite + best);
}
