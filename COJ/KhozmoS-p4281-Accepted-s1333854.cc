#include <bits/stdc++.h>

using namespace std;


#define f first
#define s second
#define pb push_back
#define db double
#define sz(c) (c).size()
#define all(c) (c).begin(),(c).end()

typedef long long ll;
typedef pair <int , int > ii;
typedef pair <ii , int > iii;
typedef vector <int> vi;
typedef vector <ii> vii;
typedef vector <vi> vvi;
typedef vector <vii> vvii;

const ll mod = 1e9+5;
const int MAX = 1e5+5;


int dp[6][5005][11];
// B < D*2 | D < C*2 | C < B*2

void bigMult( string &x , int dig , int id) {
    int rest = 0;
    for(int i = x.size()-1 ; i >= 0 ; i--)
    {
        int cur =  dig * (x[i]-48) + rest;
        rest = cur/10;
        cur %= 10;
        x[i] = char(cur+48);
        dp[dig][id][cur]++;
    }
    if(rest) {
        x = char(rest+48)+x;
        dp[dig][id][rest]++;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    string two = "1";
    string five = "1";
    dp[2][0][1]++;
    dp[5][0][1]++;
    for(int i = 1; i <= 5000 ; i++) {
        bigMult(two,2,i);
        bigMult(five,5,i);
    }
    int t;cin>>t;
    while(t--) {
        int a ,b;
        cin>>a>>b;
//        cout<<pot5[b-a]<<"\n";

        if( a > b ) {
            int id = a-b;
            cout<<dp[2][id][0]+min(a,b)<<"\n";
            for(int d = 1 ; d < 10 ; d++)
                cout<<dp[2][id][d]<<"\n";
//            cout<<pot2[a-b]<<" "<<a-b<<"\n";
            cout<<(b + 1 + floor((a-b) * (log10(2))))<<"\n";
        }else {
            int id = b-a;
            cout<<dp[5][id][0]+min(a,b)<<"\n";
            for(int d = 1 ; d < 10 ; d++)
                cout<<dp[5][id][d]<<"\n";
            cout<<(a + 1 + floor((b-a) * (log10(5))))<<"\n";
        }
    }
}
