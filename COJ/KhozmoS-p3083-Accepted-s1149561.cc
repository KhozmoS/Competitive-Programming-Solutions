#include <bits/stdc++.h>

using namespace std;


const int MAX = 1e3 + 5;
int ans = 1000000000 , n , pos;
string ar[MAX];

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);

    cin>>n;

    for(int i = 0 ; i < n ; i++)
    {
        int x , y;cin>>ar[i];
        cin>>x>>y;
        //(x^2) + (y^2)
        if(x * x + y * y < ans)
        {
            ans = x * x + y * y;
            pos = i;
        }
    }
    cout<<ar[pos]<<"\n";
}
