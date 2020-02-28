#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9+7;

int dp[52][27][27][27];

int n;
string a , b , num;

int F(int pos , int five , int two , int three, int cur , bool flag)
{
    if(num[pos] > char(cur+48))
        flag = true;
    if(num[pos] < char(cur+48) && !flag) {
       // cout<<pos<<" "<<cur<<" "<<num<<"\n";
        return 0;
    }
    if(three>25||two>25||five>25||(three+two>25))
        return 0;

    if(pos == (n-1)){
      //  cout<<two<<" "<<three<<" "<<five<<"\n";
        return ((two+three)==five && (two||three));
    }
    if(flag && dp[pos][five][two][three] != -1) return dp[pos][five][two][three];

    int res = 0;
    for(int d = 0 ; d <= 9 ; d++)
        res += F(pos+1 , five+(d==5) , two+(d==2) , three+(d==3) , d , flag) , res %= mod;

    return dp[pos][five][two][three]=res;
}

bool ok(string x)
{
    int t = 0 , th = 0 , f = 0;
    for(int i = 0 ; i < x.size() ; i++)
        t += (x[i]=='2') ,
        th += (x[i]=='3') ,
        f += (x[i]=='5');
    return ((t+th)==f && (t||th));
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t;cin>>t;
    while(t--){

        cin>>a>>b;

        memset(dp , -1 , sizeof(dp));
        // cout<<dp[0][0][0][0]<<"\n";
        num = "0"+b;
        n = num.size();
        int hi = F(0 , 0 , 0 , 0 , 0 , 0);


        num = "0"+a;
        n = num.size();
        memset(dp , -1 , sizeof(dp));
        int lo = F(0 , 0 , 0 , 0 , 0 , 0);


        cout<<(hi-(lo-ok(a)+mod)%mod+mod)%mod<<"\n";
    }
}
//1 100000000000000000000000000000000000000000000000000
