#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll pot[70];

string to_bin(ll x)
{
    string res = "";
    res.reserve(33);
    while(x != 0)
    {
        res = char((x % 2) + '0') + res;
        x /= 2;
    }

    return res;
}
ll to_num(string cad)
{
    cad.reserve(33);
    ll res = 0;
    reverse(cad.begin(), cad.end());

    for(int i = 0 ; i < cad.size() ; i++) res += (cad[i] == '1' ? pot[i] : 0);


    return res;
}
bool mk[200];
int main()
{
    //cout<<to_bin(3999995011);
    ios_base::sync_with_stdio(0);cin.tie(0);

     pot[0] = 1;
     for(int i = 1 ; i < 64 ; i++)
        pot[i] = pot[i - 1] * 2;
     int t;
     cin>>t;

     while(t--)
     {
         ll n;
         cin>>n;
         string num = to_bin(n);
         num.reserve(35);
         int tn = num.size();

         while(tn < 32){
            num = '0' + num;
            tn++;
         }
         int mod = num.size();
         //cout<<num<<"\n";
         for(int i = 0 ; i < mod ; i++)
         {
            string ver = "";
            ver.reserve(5);
           for(int j = i ; j < (i + 5) ; j++)
              ver += num[j % mod];

         //  cout<<to_num(ver)<<"\n";
           mk[to_num(ver)] = true;
         }
         //cout<<mod<<"\n";
          string ans[] = {"yes\n" , "no\n"};
          int it = 0;
         for(int i = 0 ; i <= 31 ; i++)
         {
             if(!mk[i])
             {
                 it = 1;
             }
             mk[i] = false;
         }
         cout<<ans[it];
     }


    return 0;
}
