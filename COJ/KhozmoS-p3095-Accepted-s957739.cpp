#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1111111;

int Fib[MAXN];

void generar()
{
    Fib[1] = 1;
    Fib[2] = 1;

    for(int i = 3 ; i < MAXN ; i++)
    Fib[i] = ((Fib[i - 1] % 10) + (Fib[i - 2] % 10)) % 10;

}


long long n;
int main()
{
    generar();

    while(cin>>n)
    cout<<Fib[n % 120]<<"\n";
    return 0;
}
