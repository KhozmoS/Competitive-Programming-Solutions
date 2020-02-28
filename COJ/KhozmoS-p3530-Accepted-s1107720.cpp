#include <bits/stdc++.h>

using namespace std;

const int MAX = 10000007;
typedef long long ll;


int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);

    int n;
    cin>>n;
    if(n == 1) {cout<<"1\n"; return 0;}

    int rn = (int)sqrt(n);
    ll ans = 3;
    for(int i = 2 ; i <= rn ; i++)
    {
        if(n % i == 0)
        {
            int dn = n / i;
            int rdn = (int)sqrt(n / i);
            if(dn == i)
            ans += 3;

            else ans += 6;

            for(int j = i  ; j <= rdn ; j++)
            {
                if(dn % j == 0){
                int ar[3];
                ar[0] = i; ar[1] = j; ar[2] = dn / j;
                sort(ar , ar + 3);
                 if(i == j && j == rdn)
                    ans ++;
                 else if(ar[0] != ar[1] && ar[1] != ar[2] && ar[2] != ar[0])
                    ans += 6;
                 else
                    ans += 3;
                }
            }

        }
    }
        cout<<ans<<"\n";
}
