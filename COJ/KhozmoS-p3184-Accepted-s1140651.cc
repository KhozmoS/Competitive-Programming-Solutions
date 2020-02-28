#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll k , d;


int main()
{
    scanf("%ld%ld" , &k , &d)
;
    ll ans = (d - 1) / log10(k);

    printf("%ld\n" , ans+1);
;
}
