#include <bits/stdc++.h>

using namespace std;



const int maxn = 15;
typedef long long ll;
int n;
int A[maxn];
bool mk[maxn];
ll ans = 1e18;
void ver()
{
    int a[maxn] , b[maxn];
    int c = 0 , d = 0;
    ll num1 = 0; ll num2 = 0;
    for(int i = 0 ; i < n ; i++)
        if(mk[i])
        a[c++] = A[i];
        else
        b[d++] = A[i];

    if(!c || !d) return;
    sort(a , a + c);
    sort(b , b + d);
    for(int i = 0 ; i < c ; i++) {if(a[i]){ swap(a[i] , a[0]); break;}}
    for(int i = 0 ; i < d ; i++) {if(b[i]){ swap(b[i] , b[0]); break;}}

    for(int i  = 0 ; i < c ; i++) num1 = (num1 * 10 + a[i]);
    for(int i  = 0 ; i < d ; i++) num2 = (num2 * 10 + b[i]);
    if(!num1 || !num2) return;
    ans = min(ans , num1 + num2);
}
void F(int pos)
{
    if(pos == n){
        ver();return;
    }
    mk[pos] = true;
    F(pos+1);
    mk[pos] = false;
    F(pos+1);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);


    while(cin>>n && n)
    {
        for(int i = 0 ; i < n ; i++)
            cin>>A[i];
        F(0);
        cout<<ans<<"\n";
        ans = 1e18;
    }
    return 0;
}
