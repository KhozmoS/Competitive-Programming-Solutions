#include <bits/stdc++.h>

using namespace std;
const int MAX = 1e6+1;
int ab[MAX];

void update(int x)
{
    for(; x < MAX ; x += (x&-x))
        ab[x] += 1;
}

int sum(int x)
{
    int res =0;
    for(; x > 0 ; x -= (x&-x))
        res += ab[x];
    return res;

}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);

    int q;cin>>q;
    while(q--)
    {
        int ty;cin>>ty;
        if(ty == 2)
        {
            int a ,b;cin>>a>>b;
            cout<<sum(b)-sum(a-1)<<"\n";
        }
        else
        {
            int x;cin>>x;
            update(x);
        }
    }

}