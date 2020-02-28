#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair <LL, LL> par;

const double EPS = 0.000000001;

par simplifica(par A){
    LL x = __gcd(A.first, A.second);
    A.first /= x;
    A.second /= x;
    return A;
}

par Sum(par A, par B){
    LL d = (A.second * B.second) / (__gcd(A.second, B.second));
    LL n = (d / A.second * A.first) + (d / B.second * B.first);
    par x = simplifica(par(n, d));
    return x;
}

int main()
{
    LL v1, v2, d1, d2, k = 1;
    while(cin >> v1 >> d1 >> v2 >> d2){
        if(v1 == 0)break;
        cout << "Case #" << k++ << ": ";

        par A = par(d1, v1);
        par B = par(d2, v2);

        //cout << "A  >> " << A.first << "/" << A.second << "\n";
        //cout << "B  >> " << B.first << "/" << B.second << "\n";

        par ave = Sum(A, B);
        //cout << "AVE  >> " << ave.first << "/" << ave.second << "\n";
        ave.second *= 2;

        //cout << a << "  " << b << "\n";
        LL mcm = (A.second * B.second) / __gcd(A.second, B.second);
        LL a = mcm / A.second * A.first;
        LL b = mcm / B.second * B.first;

        if(a < b)
            cout << "You owe me a beer!\n";
        else
            cout << "No beer for the captain.\n";
        cout << "Avg. arrival time: ";


        ave = simplifica(ave);
        if(ave.first % ave.second == 0)
            cout << ave.first / ave.second << "\n";
        else
            cout << ave.first << "/" << ave.second << "\n";
    }

    return 0;
}