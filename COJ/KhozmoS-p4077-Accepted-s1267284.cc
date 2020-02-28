#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll mod = 1e9+7;
ll a , b , c , d , e , f;
struct matriz{
    ll m[5][5];

    matriz()
    {
        memset(m , 0 , sizeof(m));
        m[0][0] = a;
        m[0][2] = b;
        m[0][3] = 1;
        m[1][1] = d;
        m[1][2] = e;
        m[1][4] = 1;
        m[2][1] = 1;
        m[3][3] = 1;
        m[4][4] = 1;
    }
    matriz(int x)
    {
        memset(m , 0 , sizeof(m));
        for(int i = 0; i < 5; i++)
            m[i][i] = x;
    }

    matriz operator*(const matriz &X) const{
        matriz res;
        memset(res.m , 0 , sizeof(res.m));

        for(int i = 0 ; i < 5; i++)
            for(int j = 0 ; j < 5 ; j++)
                for(int k = 0 ; k < 5; k++)
                    res.m[i][j] = (res.m[i][j] + (m[i][k] * X.m[k][j] % mod)) % mod;
        return res;
    }


};

matriz exp(matriz m , int b)
{
        matriz res = matriz(1);
        while(b)
        {
            if(b&1)
                res = res * m;
            m = m*m;
            b >>= 1;
        }
        return res;
}
ll recurrence[5];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>a>>b>>c>>d>>e>>f;
	recurrence[0] = 1;
	recurrence[1] = 1;
	recurrence[2] = 0;
	recurrence[3] = c;
	recurrence[4] = f;
	int t;cin>>t;

	while(t--){
	    int n;cin>>n;
        matriz ans = exp(matriz() , n-1);
        ll solve = 0;
        for(int i = 0 ; i < 5 ; i++)
            solve = (solve + (ans.m[0][i] * recurrence[i] % mod))%mod;
        cout<<solve<<"\n";
    }

}
