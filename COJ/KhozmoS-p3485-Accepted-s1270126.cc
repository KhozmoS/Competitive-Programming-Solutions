#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n , k;
    cin>>n>>k;

    if(1==k)
    {
        if(n<4)
            cout<<"NO\n";
        else
        {
            cout<<"YES\n";
            cout<<4<<"\n";
            cout<<"1 2\n";
            cout<<"2 3\n";
            cout<<"3 4\n";
            cout<<"4 2\n";
        }
        return 0;
    }
    if(k+2>n)
    {
        cout<<"NO\n";
        return 0;
    }
    cout<<"YES\n";
    cout<<(k)*(k+1)/2<<"\n";
    for(int i = 1 ; i < k ; i++)
    {
        for(int j = i+1 ; j <= k+1 ; j++)
            cout<<i<<" "<<j<<"\n";
    }
    cout<<k<<" "<<k+2<<"\n";
}
