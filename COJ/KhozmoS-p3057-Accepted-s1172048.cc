#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e5 + 5;

typedef long long ll;

ll A , B;
string cad;
ll AC[5005];
ll F(int in , int fn)
{
    ll res = 0;
    while(fn > in)
    {
        if(cad[fn] == 'B')
            res += (A - B) * (AC[fn] - AC[in-1]);
            fn--;
    }
    return res;
}
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>A>>B;
    cin>>cad;
    int sz = cad.size();
    cad = " " + cad + " ";
    int in = 1; int fn = sz;

    for(int i = in ; i <= fn ; i++)
        AC[i] += AC[i-1] + (cad[i] == 'W');

    ll ans = 1e18;
    ll sum = 0;
    while(in < fn)
    {
        if(cad[in] == 'W');
        else in++;
        if(cad[fn] == 'B');
        else fn--;

        if(cad[in] == 'W' && cad[fn] == 'B' && in < fn)
        {
           ans = min(ans , F(in , fn) + sum);
           swap(cad[in] , cad[fn]);
           sum += A;
        }
    }
    cout<<min(ans , sum)<<"\n";
}
