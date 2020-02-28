#include <bits/stdc++.h>

using namespace std;
int power(int x , int e)
{
    if(e == 0) return 1;

    if(e % 2 != 0)
    return (((power(x , e - 1)) % 4) * (x % 4)) % 4;

    int r = e / 2;
    return ((power(x , r) % 4) * (power(x , r) % 4)) % 4;
}
int sol , t;
string num;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>t;
    while(t--)
    {
        int x;
        cin>>num;
        int ta = num.size();
        reverse(num.begin() , num.end());
        for(int i = 0 ; i < ta ; i++)
        {
          x = power(3 , i);
          int sumale = (((num[i] - '0') ) * (x )) % 4;
          sol += sumale;
          //cout<<x<<"\n";
        }
        if(sol % 4 == 0)
        cout<<"YES\n";

        else cout<<"NO\n";
        sol = 0;
    }
    return 0;
}
