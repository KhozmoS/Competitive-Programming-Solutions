#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e5 + 5;

bool mark[MAX];
int p, sol[MAX], primos[MAX];

vector <int> v;

void primeDes(int n) {
    for (int i = 0; i < p && primos[i] * primos[i] <= n; ++i) {
        if (n % primos[i] == 0)
            v.push_back(primos[i]);
        while (n % primos[i] == 0)
            n /= primos[i];
    }
    if(n != 1)
        v.push_back(n);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for(int i = 4; i < MAX; i += 2)
        mark[i] = true;
    for(int i = 3; i * i < MAX; i += 2)
        if(!mark[i])
            for(int j = i * i; j < MAX; j += 2 * i)
                mark[j] = true;

    primos[p++] = 2;
    for(int i = 3; i < MAX; i += 2)
        if(!mark[i])
            primos[p++] = i;

    long long t, n;

       long long cant = 2;

        cin >> n;
        if(n == 1)
        {
          cout<<"0/1\n";
          return 0;
        }
        if(n == 2)
        {
           cout<<"1/1\n";
          return 0;
        }
        int num = 2;
        while(cant <= n){
        v.clear();
        long long muld = 1;
        long long muln = 1;
        primeDes(num);
        for (int i = 0; i < v.size(); i++) {
            muld *= v[i];
            muln *= v[i] - 1;
        }
        cant += ((long)num / muld) * muln;
        if(cant >= n){
        cant -= (((long long)num / muld) * muln);
        for(int i = 1 ; i < num ; i++)
        {
            if(__gcd(i , num) == 1)
              cant++;
            if(cant == n){
                cout<<i<<"/"<<num<<"\n";
                return 0;
            }
        }
        }
        num++;
        }
}
