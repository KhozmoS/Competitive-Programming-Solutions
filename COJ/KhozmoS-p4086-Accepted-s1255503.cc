#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll B = 323;
const int mod = 1e9+7;

int H1[1111111] , H2[1111111];
int P1[1111111] , P2[1111111];


string cad;int n , k , ans , AC[1111111];

bool is_pal(int x , int y)
{
    int a = (H1[y] - ((int)((ll)(H1[x-1]) * (ll)(P1[y-x+1]) % (ll)(mod))) + mod) % mod;
    int b = (H2[x] - ((int)((ll)(H2[y+1]) * (ll)(P1[y-x+1]) % (ll)(mod))) + mod) % mod;

    return (a==b);
}

void bin(int x , int y)
{
    int mn = 0; int mx = min(x-1 , n-y);mx++;
    while(mn+1<mx)
    {
        int mt = (mn + mx) >> 1;
//        if(flag){ cout<<x-mt<<" "<<y+mt<<" "<<is_pal(x-mt , y+mt)<<"\n";}
        if(is_pal(x-mt , y+mt))
            mn = mt;
        else mx = mt;
    }
    x -= mn; y += mn;
//    if(flag){
//        cout<<x<<" "<<y<<"\n";
//    }
    if(y-x+1 >= k)
        AC[x]++ , AC[y+1]--;

}
int main()
{

    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n>>k;
    cin>>cad;
    cad = " "+cad;
    P1[0] = 1ll;
    P2[n+1] = 1ll;
    for(int i = 1 ; i <= n ; i++)
    {
        int j = n-i+1;
        H1[i] = (((ll)(H1[i-1]) * B % (ll)(mod)) + (cad[i]-'a'+1)) % mod;
        H2[j] = (((ll)(H2[j+1]) * B % (ll)(mod)) + (cad[j]-'a'+1)) % mod;
        P1[i] = ((ll)(P1[i-1]) * (ll)(B)) % (ll)(mod);
    }
    /*for(int i = 1 ; i <= n ; i++)
        cout<<H1[i]<<" ";
        cout<<"\n";
    for(int i = 1 ; i <= n ; i++)
        cout<<H2[i]<<" ";*/

    for(int i = 1 ; i < n ; i++)
    {
        bin(i , i);
        if(cad[i] == cad[i+1])
            bin(i , i+1);
    }/*
    8 3
asdbaaba
    */
    for(int i = 1 ; i <= n ; i++){
        AC[i] += AC[i-1];
        ans += !(AC[i]);
//        cout<<AC[i]<<" ";
    }
//    cout<<"\n";
    cout<<ans<<"\n";

}
