#include<bits/stdc++.h>

using namespace std;

long long fi(long long n)
{
    long long e;
    long long sol = n;
    if(n % 2 == 0)
    {
        //sol *= 1;
        sol /= 2;
        while(n % 2 == 0)
        {
            n /= 2;
        }
    }
    //cout << n << endl;
    for(int i = 3; i * i <= n; i += 2)
    {
        if(n % i == 0)
        {
            sol *= i - 1;
            sol /= i;
            while(n % i == 0)
            {
                n /= i;
            }
        }
    }
    if(n > 1)
    {
        sol *= n - 1;
        sol /= n;
    }
    return sol;
}

int main()
{
    long long n;

    while(cin >> n)
    {
        long long sol = n - fi(n);
        cout << sol << endl;
    }
    return 0;
}
