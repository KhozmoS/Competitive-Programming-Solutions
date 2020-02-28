#include <bits/stdc++.h>

using namespace std;
#define endl '\n'

typedef long long int int64;

int arr[] = {0,1,2,9,262144};

int phi(int n)
{
    int r = n;
    if(n%2 == 0)
    {
        while(n%2==0)n/=2;
        r/=2;
    }
    for(int i = 3; i*i<=n; i+=2)if(n%i == 0)
    {
        while(n%i==0)n/=i;
        r/=i;r*=(i-1);
    }
    if(n>1){r/=n;r*=(n-1);}
    return r;
}

int fast_exp(int b, int p, int m)
{
    if(p == 0)return 1;
    int d = fast_exp((1LL*b*b)%m,p/2,m);
    if(p&1)d=(1LL*d*b)%m;
    return d;
}

int exponial(int n, int m)
{
	if(n==1&&m>1)return 1;
	if(m==1)return 0;
	if(n<=5)return fast_exp(n,arr[n-1],m);
	return fast_exp(n,exponial(n-1,phi(m)) + phi(m),m);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);

	int n,m;cin>>n>>m;
	cout << exponial(n,m) << endl;

	return 0;
}
