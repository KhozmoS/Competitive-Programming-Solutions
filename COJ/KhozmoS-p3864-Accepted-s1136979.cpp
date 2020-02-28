#include <bits/stdc++.h>

using namespace std;

#define pb(x) push_back(x)

typedef long long LL;

const int MAXN = 60;
const int MAX_SQRT = 31700;

LL TP[MAXN][MAXN], TOT;
bool comp[MAX_SQRT];
vector <LL> primes, P, E;

void criba(){
    for(LL i = 4; i < MAX_SQRT; i+= 2)
        comp[i] = true;

    for(LL i = 3; i * i < MAX_SQRT; i += 2)
        if(!comp[i])
            for(LL j = i * i; j < MAX_SQRT; j += i + i)
                comp[j] = true;

    primes.pb(2);
    for(LL i = 3; i < MAX_SQRT; i += 2)
        if(!comp[i])
            primes.pb(i);
    //cout << primes.size() << endl;
}

void pascal(){

    for(int i = 0; i < MAXN; i++)
        TP[i][0] = TP[i][i] = 1;

    for(int i = 1; i < MAXN; i++)
        for(int j = 1; j < i; j++)
            TP[i][j] = TP[i - 1][j] + TP[i - 1][j - 1];
}

void factoriza(int n){
    TOT = 0;
    P.clear(); E.clear();
    for(LL i = 0; primes[i] * primes[i] <= n; i++)
        if(n % primes[i] == 0){
            int e = 0;
            while(n % primes[i] == 0)
                n /= primes[i], e++;
            P.push_back(primes[i]);
            E.push_back(e);
            TOT += e;
        }
    if(n > 1){
        P.push_back(n);
        E.push_back(1);
        TOT += 1;
    }
}

LL catalan(int n){
    return TP[2 * n][n] - TP[2 * n][n + 1];
}

LL permut(vector <LL> a, vector <LL> b){
    LL sol = 1, n = TOT, sum = 0;
    for(int i = 0; i < a.size(); i++){
        sol *= TP[n - sum][b[i]];
        sum += b[i];
        //cout << i << ") " << sol << " " << sum << endl;
    }
    return sol;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);

    pascal();
    criba();

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        factoriza(n);
        /*int cont = 0;
        for(int i = 0; i < P.size(); i++)
            cout << P[i] << ' ';
        cout <<endl;
        for(int i = 0; i < E.size(); i++)
            cout << E[i] << ' ';
        cout <<endl;*/
        LL a = permut(P, E);
        LL b = catalan(TOT - 1);
        LL sol = a * b;
        cout << sol << "\n";
    }
    return 0;
}
