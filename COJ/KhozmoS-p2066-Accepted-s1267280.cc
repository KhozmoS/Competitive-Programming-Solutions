#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll mod = 10007;

struct matriz{
    ll m[3][3];

    matriz()
    {
        memset(m , 0 , sizeof(m));
        for(int i = 0 ; i < 3 ; i++)
            for(int j = 0 ; j < 3 ; j++)
                if(i!=j)
                    m[i][j] = 3;
    }
    matriz(int x)
    {
        memset(m , 0 , sizeof(m));
        for(int i = 0; i < 3 ; i++)
            m[i][i] = x;
    }

    matriz operator*(const matriz &X) const{
        matriz res;
        memset(res.m , 0 , sizeof(res.m));

        for(int i = 0 ; i < 3 ; i++)
            for(int j = 0 ; j < 3 ; j++)
                for(int k = 0 ; k < 3 ; k++)
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
int recurrence[3];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;cin>>n;
    cin>>recurrence[0]>>recurrence[1]>>recurrence[2];
    matriz ans = exp(matriz() , n);
    ll solve = 0;
    for(int k = 0 ; k < 3 ; k++){
        solve = 0;
    for(int i = 0 ; i < 3 ; i++)
        solve = (solve + (ans.m[k][i] * recurrence[i] % mod))%mod;
        cout<<solve<<(k==2 ? "\n" : " ");
    }

}
