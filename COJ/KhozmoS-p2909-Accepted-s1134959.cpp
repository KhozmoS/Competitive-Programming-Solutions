#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6;

int A[MAXN];
bool comp[MAXN];
vector <int> primes;

void criba()
{
    for(int i = 4; i < MAXN; i += 2)
        comp[i] = true;

    for(int i = 3; i * i < MAXN; i += 2)
        if(!comp[i])
            for(int j = i * i; j < MAXN; j += 2 * i)
                comp[j] = true;

    primes.push_back(2);
    for(int i = 3; i < MAXN; i += 2)
        if(!comp[i])
            primes.push_back(i);
    //cout << primes.size();
}

int cantdv(int n)
{
    int sol = 1;
    for(int i = 0; primes[i] * primes[i] <= n; i++)
        if(n % primes[i] == 0)
        {
            int e = 0;
            while(n % primes[i] == 0)
                n /= primes[i], e++;
            sol *= (e + 1);
        }
    if(n > 1)
        sol *= 2;
    return sol;
}

int main(){

    //freopen(".in", "r", stdin);
   ios_base::sync_with_stdio(0);cin.tie(0);

    criba();
    for(int i = 1; i <= MAXN; i++)
        A[i] = cantdv(i);

    int t;
    //cout<<"wa\n";
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;

        int max = -1, sol = 0;
        for(int i = n; i >= 1; i--)
            if(A[i] >= max){
                max = A[i];
                sol = i;
            }
        cout << sol << "\n";
    }

    return 0;
}
