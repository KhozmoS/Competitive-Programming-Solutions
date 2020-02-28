#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int SIZE = 1e5 + 1,MOD = 1e9 + 7, MODH = 2e9 + 99,IM = (5e8 + 4);
LL B = 29,P[SIZE],P2[SIZE],B2 = 311;

int ascii(char l){
    return l - 'a' + 1;
}

LL f_hash(int ini,int fin,const vector<LL> &arr){
    return (arr[fin] - (arr[ini - 1] * P[fin - ini + 1] % MODH) + MODH) % MODH;
}

LL f_hash2(int ini,int fin,const vector<LL> &arr){
    return arr[fin] - (arr[ini - 1] * P2[fin - ini + 1]);
}

struct HASH{
  size_t operator()(const pair<long long,long long>&x)const{
    return hash<long long>()((x.first ^ x.second) * x.first + x.second);
  }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

//    freopen(".in","r",stdin);
//    freopen("002.out","w",stdout);

    P[0] = P2[0] = 1;
    for(int i = 1;i < SIZE;i++){
        P[i] = P[i - 1] * B % MODH;
        P2[i] = P2[i - 1] * B2;
    }

    int T;
    cin >> T;

    for(int nt = 1;T--;nt++){
        string S;
        int K;

        cin >> S >> K;

        int N = S.size();

        S = " " + S;

        vector<LL> H(N + 1,0),H2(N + 1,0);
        for(int i = 1;i <= N;i++){
            H[i] = (H[i - 1] * B + ascii(S[i])) % MODH;
            H2[i] = H2[i - 1] * B2 + S[i];
        }

        unordered_map<pair<LL,LL>,LL,HASH> F;
        for(int i = 1;i + K - 1 <= N;i++){
            F[make_pair(f_hash(i,i + K - 1,H),f_hash2(i,i + K - 1,H2))] += N - (i + K - 1) + 1;
        }

        long long sol = 0;
        for(int i = 1;i + K - 1 <= N;i++){
            auto qwe = &F[make_pair(f_hash(i,i + K - 1,H),f_hash2(i,i + K - 1,H2))];

            LL aux1 = (*qwe) - 1;
            LL aux2 = (*qwe) - (N - (i + K - 1) + 1);
            LL tmp = ((aux2 + aux1) % MOD) * ((aux1 - aux2 + 1) % MOD) % MOD * IM % MOD;

            sol = (sol + tmp) % MOD;

            (*qwe) -= N - (i + K - 1) + 1;
        }

        cout << "Case #" << nt << ": "<< sol << '\n';
    }

    return 0;
}