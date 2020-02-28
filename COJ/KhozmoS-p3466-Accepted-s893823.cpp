#include <bits/stdc++.h>

using namespace std;

long long pow(long long b, long long e)
{
    if(e == 0)
        return 1;
    if(e % 2 == 0)
    {
        long long r = pow(b, e / 2);
        return r * r;
    }
    return b * pow(b, e - 1);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    long long N, P;
    int k = 1;
    while(cin >> N >> P)
    {
        if(N == 0)
            break;

        long long exp = P, cont = 1;
        while(exp <= N)
            exp *= P, cont++;
        cont--;

        long long x = pow(P, cont);

        while(true)
        {
            if(x <= N){
                N -= x;
                if(N == 0){
                    cout <<"Case #" << k << ": " << "yes\n";
                    break;
                }
            }
            x /= P;
            if(x == 0){
                cout <<"Case #" << k << ": " << "no\n";
                break;
            }
        }
        k++;
    }

    return 0;
}
