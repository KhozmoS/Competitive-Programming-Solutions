#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bool mk[105];

string cad;

string to(int x)
{
    string res = "";
    while(x)
    {
        res = char(x%10+48)+res;
        x/=10;
    }
    return res;
}
char pos(int x)
{
    if(x<=2) return cad[x];
    x = (x-3)%8;
    return cad[x+3];
}
int main()
{
   // ios_base::sync_with_stdio(0);cin.tie(0);

    cad = "46";
    cad = "*"+cad;
    int idx = cad.size();
    while(true)
    {
        if(mk[(cad[idx-2]-48)*10+(cad[idx-1]-48)])
            break;
        mk[(cad[idx-2]-48)*10+(cad[idx-1]-48)] = true;
        int nw = (cad[idx-2]-48)*(cad[idx-1]-48);
        cad += to(nw);
        idx += to(nw).size();
    }
   // cout<<cad<<"\n";
    int a , b , c , d;
    cin>>a>>b>>c>>d;

    cout<<pos(a)<<pos(b)<<pos(c)<<pos(d)<<"\n";
}
