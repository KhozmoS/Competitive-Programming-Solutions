#include <bits/stdc++.h>

using namespace std;
#define f first
#define s second
typedef pair <int , int> par;
const int MAX = 1e5 + 6;
//const int ln = (int)log2(MAX);
int P[20][MAX];
int N , stp , cnt;
struct info {
    int nr[2], p;
    bool operator < ( const info &b ) const {
        return nr[0] == b.nr[0] ? ( nr[1] < b.nr[1] ) : ( nr[0] < b.nr[0] );
    }
} L[MAX];

void suffixArray( char *A ) {
    N = strlen(A);
    for( int i = 0; i < N; i++ ) P[0][i] = A[i] - 'a';

    for( stp = 1, cnt = 1; cnt >> 1 < N; ++stp, cnt <<= 1 ) {
        for( int i = 0; i < N; i++ ) {
            L[i].nr[0] = P[stp - 1][i];
            L[i].nr[1] = i + cnt < N ? P[stp - 1][i + cnt] : -1;
            L[i].p = i;
           // cout<<L[i].nr[1]<<" w\n";
        }
        sort(L, L + N);
        for ( int i = 0; i < N; i++ )
            P[stp][L[i].p] = i > 0 && L[i].nr[0] == L[i - 1].nr[0] && L[i].nr[1] == L[i - 1].nr[1] ? P[stp][L[i - 1].p] : i;
    }
}

int lcp(int x, int y) {
    int k, ret = 0;
    if(x == y) return N - x;
    for( k = stp - 1; k >= 0 && x < N && y < N; k-- ) if(P[k][x] == P[k][y])
        x += 1 << k, y += 1 << k, ret += 1 << k;
    return ret;
}
char ar[MAX];
int main()
{
    
    while(scanf("%s" , ar))
    {
        long long ans = 0;
        if(ar[0] == '*') return 0;
        int las = 0;
        suffixArray(ar);
        int n = strlen(ar);
        for(int i = 1 ; i < n ; i++)
        {
            int lc = lcp(L[i - 1].p , L[i].p);
            if(lc > las)
               ans += lc - las;
            las = lc;
        }
        cout<<ans<<"\n";
    }
    return 0;
}
