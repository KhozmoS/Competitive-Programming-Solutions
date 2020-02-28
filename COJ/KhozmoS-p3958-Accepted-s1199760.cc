#include <bits/stdc++.h>

using namespace std;
const int MAX = 1e6;

typedef long long ll;
ll Bas = 311;
const ll mod = 1e9 + 7;
ll H[MAX] , B , P[MAX];
string a , b;
int sza;
ll calc(int x)
{
    return (H[sza] - (H[x] * P[sza - x] % mod) + mod) % mod;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>a>>b;
    sza = a.size();
    int szb = b.size();
    a = " "+a;
    b = " "+b;
    P[0] = 1;
    for(int i = 1; i <= sza ; i++)
    {
        P[i] = (P[i-1] * Bas) % mod;
        H[i] = (H[i-1] * Bas + (a[i] - 'a')) % mod;
    }
    for(int i = 1 ; i <= szb ; i++)
    {
        B = (B * Bas + (b[i]-'a')) % mod;
    }
    int cnt = 0;
    vector <int> v;
    for(int i = 1 ; i <= sza ; i++)
    {
        ll A = (H[i-1] * P[sza - i] % mod + calc(i)) % mod;
        if(A == B)
        {
            cnt++;
            v.push_back(i);
        }
    }
    cout<<cnt<<"\n";
    for(int i = 0 ; i < cnt ; i++)
        cout<<v[i]<<(i == (cnt-1) ? "\n" : " ");
}
