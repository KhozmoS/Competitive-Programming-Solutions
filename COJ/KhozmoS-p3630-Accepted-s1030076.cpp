#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

string a, b;

int main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0);

    LL n;
    while(true){
        scanf("%lld", &n);
        if(n == 0)break;
        LL media = n;
        LL odd, sum = 0;

        for(int i = 1; i <= n; i++){
            odd = (LL)i * 2 - 1;
            sum += (odd - media) * (odd - media);
        }
        double sol = sqrt(sum / (n - 1.0));
        printf("%.6lf\n", sol);
    }


    return 0;
}