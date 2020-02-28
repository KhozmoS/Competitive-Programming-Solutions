#include <bits/stdc++.h>

using namespace std;
const int MAX = 1e6;

string cad;
int U , D , L , R;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>cad;int sz = cad.size();
    if(sz&1){cout<<"-1\n";return 0;}
    for(int i = 0 ; i < sz ; i++)
    {
        if(cad[i] == 'U') U++;
        if(cad[i] == 'D') D++;
        if(cad[i] == 'R') R++;
        if(cad[i] == 'L') L++;
    }
    if(U < D) swap(U , D);
    if(R < L) swap(R , L);

    int res = U-D;
    int ans = 1e9;
    int l = L + res;
    if(R <= L + res) ans = min(ans , res);
    else ans = min(ans , R - ((R + l)/2));
    res = R - L;
    int d = D + res;
    if(U <= D + res) ans = min(ans , res);
    else ans = min(ans , U - ((U+d)/2));
    if((U+D)&1){
        L++;
        U--;
    }
    if((R+L)&1)
    {
        D++;
        R--;
    }

    int ans1 = (R-((R+L)/2))+(U-((U+D)/2));
    if(sz > 10000)cout<<ans1<<"\n";
    else cout<<ans<<"\n";
}
