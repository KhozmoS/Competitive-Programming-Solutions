#include <bits/stdc++.h>

using namespace std;



int n , ar[22];
int q;

map <int , int> mp;

void F(int pos , int sm)
{
    if(sm > 1000000000)
        return;
    if(pos == n) return;

    F(pos+1 , sm);
    mp[sm+ar[pos]]++;
    F(pos+1 , sm+ar[pos]);
}
int main()
{
    //cout<<2097151*(int)(log2(2097171))<<"\n";
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i = 0 ; i < n ; i++)
        cin>>ar[i];
    F(0,0);
    //cout<<cnt<<"\n";
    cin>>q;
    while(q--)
    {
        int x;cin>>x;
        if(mp.find(x) == mp.end())
            cout<<"0\n";
        else
            cout<<mp[x]<<"\n";
    }
}
/*
5
2 3 1 5 4
3
9
1
4
*/
