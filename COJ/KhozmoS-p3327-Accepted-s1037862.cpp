#include <cstdio>

using namespace std;

typedef unsigned long long ll;

ll F[20], C[20], I, P, sol;

int main(){

    F[0] = 1ull;
    for (ll i = 1; i <= 18; i++)
         F[i] = F[i-1]*i;

    ll a = 5;
    C[0] = 1;
    for (ll i=1; i <= 18; i++)
         C[i] = C[i-1]*a;
     while (1){
         scanf ("%lld%lld",&P,&I);
         if (P==I&&P==0) break;
           if (P > 0)
           sol = 2ull*(4ull*(C[I+P-1])*(F[I+P-1]/F[I]/F[P-1]));
           if (I > 0)
           sol += 2ull*(C[I+P])*(F[I+P-1]/F[I-1]/F[P]);
           if (I==0&&P==1)sol++;
           printf ("%lld\n", sol); sol = 0ull;
    }

    return 0;
}
