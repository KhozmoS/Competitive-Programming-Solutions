#include <bits/stdc++.h>

using namespace std;

int n, t, a, b, to, fin, sol, lista[12];

void comb(int mask) {
    if(mask == fin) {
        sol++;
        return;
    }
    for(int i = 1; i <= n; i++)
        if(!(mask & (1 << i)) && (mask & lista[i]) == lista[i])
            comb(mask | (1 << i));
            
}

int main() {
    cin >> n >> t;
    
    memset(lista, 0, sizeof(lista));
    
    while(t--) {
        cin >> a >> b;
        lista[b] |= 1 << a;
    }
    for(int i = 1; i <= n; i++)
        if(!lista[i])
            lista[i] = 1;
    fin = (1 << (n + 1)) - 1;
    sol ^= sol;
    comb(1);
    cout << sol << '\n';
    
    return 0;
}