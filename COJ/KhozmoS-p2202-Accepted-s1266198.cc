#include <bits/stdc++.h>

using namespace std;

long long a , b , c , d , e , f;

long long gcd(long long a , long long b)
{
    if(!b && !a) return 1;
    if(!b) return a;
    return gcd(b , a%b);
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);

    while(cin>>a>>b>>c>>d>>e>>f)
    {
        long long g = gcd(gcd(abs(a-d) , abs(b-e)) , abs(c-f));
        long long jmp = abs(a-d)/g;
        long long ans = 0;
        if(jmp)
            ans = abs(a-d)/jmp;
        cout<<ans+1<<"\n";
    }

}
