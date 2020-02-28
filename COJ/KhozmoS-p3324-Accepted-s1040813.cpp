#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int MAX_SQRT = 1000007;

bool comp[MAX_SQRT];
vector <LL> primes;

void criba()
{
    for(int i = 4; i < MAX_SQRT; i += 2)
        comp[i] = true;

    for(int i = 3; i * i < MAX_SQRT; i += 2)
        if(!comp[i])
            for(int j = i * i; j < MAX_SQRT; j += 2 * i)
                comp[j] = true;

    primes.push_back(2);
    for(int i = 3; i < MAX_SQRT; i += 2)
        if(!comp[i])
            primes.push_back(i);
    //cout << primes.size();
}

LL pow(LL b, LL e)
{
    if(e == 0)
        return 1LL;
    if(e & 1)
        return b * pow(b, e - 1);
    LL r = pow(b, e / 2);
    return r * r;
}

int main()
{
    criba();

    while(true){

        LL N;
        cin >> N;

        if(N == 0)
            break;

        if(N == 1){
            cout << "2\n";
            continue;
        }
        LL sol = 1;
        for(int i = 0; primes[i] * primes[i] <= N; i++)
            if(N % primes[i] == 0)
            {
                LL e = 0;
                while(N % primes[i] == 0)
                    N /= primes[i], e++;

                sol *= (primes[i] - 1) * pow(primes[i], e - 1);
            }
        if(N > 1)
            sol *= (N - 1);

        cout << sol << "\n";
    }
    return 0;
}
