#include <bits/stdc++.h>

using namespace std;

int n, sol1, sol2, lista[1005];

int main() {
    cin >> n;

    for(int i = 1; i <= n; i++)
        cin >> lista[i];

    sort(lista + 1, lista + n + 1);

    lista[0] = lista[n];
    lista[++n] = lista[1];

    sol1 = sol2 = 0;

    for(int i = 1; i < n; i += 2) {
        sol1 += min(abs(lista[i] - lista[i-1]), 24 - abs(lista[i] - lista[i-1]));
        sol2 += min(abs(lista[i+1] - lista[i]), 24 - abs(lista[i+1] - lista[i]));
    }

    cout << min(sol1, sol2) << '\n';
}