#include<bits/stdc++.h>


using namespace std;
#define PB push_back
const int mod = 10007;
typedef unsigned long long ll;
typedef vector <ll> vi;


string r[8] = {""," ","  ","   ","    ","     ","      ","       "},
       alp[17] = {"0","1","2","3","4","5","6","7","8","9","A","B","C","D","E","F"};
int num[1000];

ll exp(ll a , ll b)
{
    if(b == 0) return 1;
    if(b == 1) return a;
    ll p = exp(a , b/2);
    if(b&1) return p*p*a;
    return p*p;
}

ll todec(string x , ll b)
{
    reverse(x.begin() , x.end());
    ll res = 0;
    for(int i = 0 ; i < x.size() ; i++)
    {
        res += (num[x[i]]) * exp(b , (ll)i);
    }
    return res;
}
string F(ll x , ll b)
{
    string res = "";
    while(x)
    {
        res = alp[x % b] + res;
        x /= b;
    }
    return res;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    num['0'] = 0;
    num['1'] = 1;
    num['2'] = 2;
    num['3'] = 3;
    num['4'] = 4;
    num['5'] = 5;
    num['6'] = 6;
    num['7'] = 7;
    num['8'] = 8;
    num['9'] = 9;
    num['A'] = 10;
    num['B'] = 11;
    num['C'] = 12;
    num['D'] = 13;
    num['E'] = 14;
    num['F'] = 15;

    string cur; ll b1 , b2;
    while(cin>>cur>>b1>>b2){
    string ans = F(todec(cur , b1) , b2);
    if(ans.size() > 7)
    {
        cout<<"  ERROR\n";
        continue;
    }
    cout<<r[7-ans.size()]<<ans<<"\n";
    }
}
