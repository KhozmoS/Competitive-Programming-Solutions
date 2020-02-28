#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pb push_back
typedef long long ll;


string toBin(ll x) {
    string res = "";
    while(x) {
        res = char(x%2+48) + res;
        x /= 2;
    }
    return res;
}
ll toNum(string x) {
    ll res = 0;
    ll pt2 = 1;
    reverse(x.begin() , x.end());
    for(int i = 0 ; i < x.size() ; i++) {
        res += pt2*(x[i]-48);
        pt2*=2ll;
    }
    return res;
}
int ac[105];

int main()
{
//    cout<<toNum("1010");
    ios_base::sync_with_stdio(0);cin.tie(0);



    ll m;int k;
    while(cin>>m>>k){
        string cad = toBin(m);
        if(k > cad.size()) {
            string ans = "";
            while(k--) {
                ans += "1";

            }
             cout<<toNum(ans)<<"\n";
        } else {
            ll ans = 1e18;
            for(int i = cad.size()-1 ; i-k+1 >= 0 ; i--) {
                string tmp = cad;
                for(int j = i-k+1; j <= i ; j++){
                    tmp[j]='1';
                }
                bool ok = false;
                int cnt = 0;
                for(int j = 0 ; j < tmp.size() ; j++) {

                    if(ok && !(j>=(i-k+1)&&j<=i)){
//                        cout<<i-k+1<<" "<<i<<" "<<j<<"\n";
                     tmp[j] = '0';
//                     cout<<cnt<<" "<<k<<"\n";
                    }
                    if(tmp[j]>cad[j])
                        ok = true;
                    cnt += (tmp[j]=='1');
                }
                ans = min(ans , toNum(tmp));
            }

            cout<<ans<<"\n";
        }
    }
}
