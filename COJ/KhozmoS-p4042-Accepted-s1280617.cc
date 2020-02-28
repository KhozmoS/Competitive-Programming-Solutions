#include <bits/stdc++.h>

using namespace std;
int arr[500][500];
        int ansr[500];
        int ansc[500];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int x , y , z;
        int ans = 0;
        for(int i = 0; i < 5 ; i++){
            bool ok = false;
            cin>>x>>y>>z;
            if(y) ok = (x/y==z && x%y==0);

            if(x*y == z || x+y==z || x-y==z) ok = true;
            ans += ok;
        }
        cout<<ans<<"\n";
    }
}
