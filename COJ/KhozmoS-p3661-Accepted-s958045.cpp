#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int MAXN = 1e6 + 7;

string alfa = "ABCDEFGHIJKLMNOPQRSTUVWXYZ_.";

LL A[MAXN];

int damePos(char c){
    for(int i = 0; i < alfa.size(); i++)
        if(c == alfa[i])
            return i;
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int N; string cad;
    int L = alfa.size();
    while(true){
            cin >> N;
            if(N == 0)break;
            cin >> cad;

            reverse(cad.begin(), cad.end());
            string aux = "";

            for(int i = 0; i < cad.size(); i++)
            {
                int p = damePos(cad[i]);
                p = (p + N) % L;
                aux += alfa[p];
            }
            cout << aux << "\n";


    }



    return 0;
}
