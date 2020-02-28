#include <bits/stdc++.h>

using namespace std;

set <int> ind;
map <int , int> m;

void prep()
{
    int pot = 1;
    m[1] = 1;
    ind.insert(1);
    int i = 2;
    int n = 1;
    while(i < 32)
    {
       pot *= 2;
       n += pot;
       m[n] = i;
       ind.insert(n);
       i++;
    }
}
string f(int pos , int ta)
{
    string res = "";
    int fn = pow(2 , ta);
    while(fn >= 2)
    {
        //cout<<pos<<"\n";
        if(pos <= fn >> 1)
            res += '4';
        else{
            pos = pos - (fn>>1);
            res += '7';
        }
        fn >>= 1;
    }
    return res;
}
int main()
{
    prep();
    int n; cin>>n;
    set <int> :: iterator  pos = ind.lower_bound(n);
    if(*pos != n) pos--;
    //cout<<*pos<<"\n";
    //cout<<m[*pos];
    cout<<f(n - *pos + 1 , m[*pos])<<"\n";
}
