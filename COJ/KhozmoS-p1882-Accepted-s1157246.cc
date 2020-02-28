#include <bits/stdc++.h>

using namespace std;
#define ff first.first
#define fs first.second
#define s second
typedef pair <int , int> par;
typedef pair <par , int> trio;
const int MAX = 1e4 * 5 + 6;
trio L[MAX];
//const int ln = (int)log2(MAX);
int P[20][MAX] , N , stp , cnt;

void suffixArray( char *A ) {
    N = strlen(A);
    for( int i = 0; i < N; i++ ) P[0][i] = A[i] - 'A';

    for( stp = 0, cnt = 1; cnt >> 1 < N; cnt <<= 1 ) {
        stp++;
        for( int i = 0; i < N; i++ ) {
            L[i].ff = P[stp - 1][i];
            L[i].fs = i + cnt < N ? P[stp - 1][i + cnt] : -1;
            L[i].s = i;
        }
        sort(L, L + N);
        for ( int i = 0; i < N; i++ )
            P[stp][L[i].s] = i > 0 && L[i].ff == L[i - 1].ff && L[i].fs == L[i - 1].fs ? P[stp][L[i - 1].s] : i;
    }
}

int lcp(int x, int y) {
    int k, ret = 0;
    if(x == y) return N - x;
    for( k = stp; k >= 0 && x < N && y < N; k-- )
      if(P[k][x] == P[k][y])
      x += 1 << k, y += 1 << k, ret += 1 << k;

    return ret;
}
char ar[MAX];
int main()
{
   // cout<<('r' - 'a');
    scanf("%s" , ar);

       // if(ar[0] == '*') return 0;
        int las = 0;
        suffixArray(ar);
        int n = strlen(ar);

        int in = 0; int fn = 0;
        int apar = 0;
        int posans = 0;
        int bestapar = 0;
      //  cout<<L[in].s<<"\n";
        while(fn < n)
        {
            if(lcp(L[in].s , L[fn].s) >= 8){
                apar++;
                fn++;
                if(apar > bestapar)
                {
                    bestapar  = apar;
                    posans = L[in].s;
                }
            }
            else
            {
                in++;
                apar = 0;
                if(in > fn) fn++;
            }
        }
        if(bestapar < 2){
            cout<<"Solution was not found\n";
            return 0;
        }

        for(int i = posans ; i < posans + 8 ; i++)
            cout<<ar[i];
        cout<<"\n";
}
