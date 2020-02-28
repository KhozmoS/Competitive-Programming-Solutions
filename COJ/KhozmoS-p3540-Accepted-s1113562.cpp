//By Forte11
#include <bits/stdc++.h>

using namespace std;

#define cik(i, a, b, c) for(int i =(a); i <=(b); i +=(c))
#define acik(i, a, b, c) for(int i =(a); i >=(b); i -=(c))
#define ull unsigned long long

const int maxn = 1e3 + 5;
const ull base = 311;

map<ull, int> Frek;
vector<ull> V;
ull TH[maxn], P[maxn];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int F; cin >> F;

    string A; cin >> A;

    int lon = A.size();
    A = " " + A;

    P[0] = 1;
    TH[0] = 0;
    cik(i, 1, lon, 1){
        TH[i] = TH[i - 1] * base + (ull)(A[i]);
        P[i] = P[i - 1] * base;
    }

    int Sol = -1;
    acik(i, lon, 1, 1){
        Frek.clear();
        V.clear();
        cik(j, i, lon, 1){
            ull H = TH[j] - TH[j - i] * P[i];

            if(Frek.find(H) == Frek.end()){
                Frek[H] = 1;
            }
            else{
                Frek[H]++;
            }

            if(Frek[H] == F){
                V.push_back(H);
            }
        }

        int lonv = V.size() - 1;
        cik(j, 0, lonv, 1){
            if(Frek[V[j]] == F){
                Sol = i;
                goto A;
            }
        }
    }

    A:

    cout << Sol << "\n";

    return 0;
}
