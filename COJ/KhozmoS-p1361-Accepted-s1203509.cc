#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
vector <int> cool;

bool is_cool(int x)
{
    int sq = sqrt(x);
    if(sq*sq!=x) return false;
    int in = 0; int fn = 464;
    while(in+1<fn)
    {
        int mt = (fn+in)>>1;
        if(mt*mt*mt>=x)
            fn = mt;
        else in = mt;
    }
    if(fn*fn*fn!=x)return false;
    return true;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    for(int i = 1 ; i <= 100000000 ; i++)
        if(is_cool(i))
            cool.push_back(i);
    int a , b;
    while(cin>>a)
    {
        cin>>b;
        int lo = lower_bound(cool.begin() , cool.end() , a) - cool.begin();
        int hi = upper_bound(cool.begin() , cool.end() , b) - cool.begin();
        cout<<hi-lo<<"\n";
    }
}
