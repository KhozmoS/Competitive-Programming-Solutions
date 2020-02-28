#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const LL MAXSQ = 1e4 + 7;
bool comp[MAXSQ];
vector <LL> primes;

void criba(){
    for(LL i = 4; i < MAXSQ; i += 2)
        comp[i] = true;

    for(LL i = 3; i * i < MAXSQ; i += 2)
        if(!comp[i])
            for(LL j = i * i; j < MAXSQ; j +=  2 * i)
                comp[j] = true;

    primes.push_back(2);
    for(LL i = 3; i < MAXSQ; i += 2)
        if(!comp[i])
            primes.push_back(i);
}

LL SOY_LOCA(LL n, LL p, LL X){
    LL sol = 0; LL e = p;
    while(n / p > 0){
        sol += n / p;
        p *= e;
    }
    return sol / X;
}

void factoriza(LL n, LL b){
    LL aux = b;
    vector<LL> p, e; LL exp = 0;
    LL x = 0, emin = LONG_MAX;
    for(LL i = 0; primes[i] * primes[i] <= n; i++){
        if(n % primes[i] == 0){
            LL exp = 0;
            while(n % primes[i] == 0){
                exp++;
                n /= primes[i];
            }
            x = primes[i];
            if(exp <= emin){
                x = primes[i];
                emin = exp;
            }
            p.push_back(primes[i]);
            e.push_back(exp);
        }
    }
    if(n > 1){
        x = n;
        p.push_back(n);
        e.push_back(1);
    }

    LL mojon = LONG_MAX;
    for(LL i = 0; i < p.size(); i++){
        LL val = SOY_LOCA(aux, p[i], e[i]);
        //cout << "va >> " << val << endl;
        mojon = min(mojon, val);
    }
    cout << mojon << "\n";
}

int main()
{
    criba();

    LL n, b;
    while(cin >> n >> b, n + b)
        factoriza(b, n);

    return 0;
}
