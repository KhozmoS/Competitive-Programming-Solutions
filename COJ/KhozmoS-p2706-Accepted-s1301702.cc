#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

string cad;
int diva[65];
set<pii> mk;
int sol[10001];

int conv(){
    int ret = 0;
    for(int i = 2 ; i < cad.size() ; i++){
        ret *= 10;
        ret += (cad[i] - '0');
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for(int N = 1 ; N <= 10000 ; N++){
        int cant = 0;
        for(int i = 1 ; i <= N ; i++)
            if(N % i == 0)
                diva[cant++] = i;


        int c = 0;
        for(int i = 0 ; i < cant ; i++){
            for(int j = 0 ; j < cant ; j++){
                if(diva[i] * diva[j] / __gcd(diva[i], diva[j]) == N){
                    if(mk.find(pii(diva[i], diva[j])) == mk.end() && mk.find(pii(diva[j], diva[i])) == mk.end()){
                        mk.insert(pii(diva[i], diva[j]));
                        c++;
                    }
                }
            }
        }

        sol[N] = c;
        mk.clear();
    }

    while(cin >> cad){
        int N = conv();
        cout << sol[N] << '\n';
    }


    return 0;
}
