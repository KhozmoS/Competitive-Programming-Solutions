#include <bits/stdc++.h>

using namespace std;
int m , d , b , t;
string num;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    b = 10; d = 128;
    //cin>>num>>b>>d;
    cin>>t; int sol = 0;
    while(t--){
     cin>>num;

    int ta = num.size();
    m = 0;
    for(int i = 0 ; i < ta ; i++)
    {
        m = (m * b + (num[i] - '0')) % d;
    }
      sol += m;
    }
    cout<<sol % d<<"\n";
    return 0;
}
