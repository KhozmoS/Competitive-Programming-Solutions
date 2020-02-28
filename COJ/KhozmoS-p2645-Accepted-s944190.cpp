#include <bits/stdc++.h>

using namespace std;


int b , a;
int suma;
string num;
int m;
int d;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    while(true)
    {
        cin>>b;
        if(!b) break;
        cin>>num;
        int ta = num.size();
        m = 0; d = 0;
        for(int i = 0 ; i < ta ; i++)
        {
            d += num[i] - 48;
        }
        for(int i = 0 ; i < ta ; i++)
        {
            m = (m * b + (num[i] - '0')) % d;
        }
        if(!m) cout<<"YES\n";
        else cout<<"NO\n";
    }

    return 0;
}
