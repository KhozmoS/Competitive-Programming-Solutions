#include<bits/stdc++.h>


using namespace std;

const int mod = 10007;
typedef vector <int> vi;
typedef vector < vi > matriz;

int n;

matriz mul(matriz a , matriz b)
{
    vi x(6 , 0);
    matriz res(6 , x);
    for(int i = 0 ; i < 5 ; i++)
        for(int j = 0 ; j < 5 ; j++)
            for(int k = 0 ; k < 5 ; k++)
                res[i][j] = (res[i][j] + a[i][k] * b[k][j]) % mod;
    return res;
}
matriz exp(matriz a , int b)
{
    vi x(6 , 0);
    matriz res(6 , x);

    res[0][0] = res[1][1] = res[2][2] = res[3][3] = res[4][4] = 1;

    while(b)
    {
        if(b&1)
            res = mul(res , a);
        b >>= 1;
        a = mul(a , a);
    }

    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);

    while(cin>>n && n)
    {
       vi x(6 , 0);
       matriz atm(6 , x);
       atm[0][1] = 1 , atm[0][2] = 1 , atm[0][3] = 1;
       atm[1][4] = 1 , atm[4][2] = 1 , atm[4][3] = 1 , atm[1][2] = 1, atm[1][3] = 1;
       atm[2][2] = 1 , atm[2][1] = 1 , atm[2][3] = 1;
       atm[3][1] = 1 , atm[3][2] = 1 , atm[3][3] = 1;

       atm = exp(atm , n);
       int ans = (atm[0][1] + atm[0][2] + atm[0][3] + atm[0][4]) % mod;
       cout<<ans<<"\n";
    }

}
