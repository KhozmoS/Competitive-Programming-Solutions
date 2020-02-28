#include <bits/stdc++.h>

using namespace std;
const int MAX = 1e3 + 5;
int ar[MAX];

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;cin>>t;

    while(t--){

    int n;cin>>n;

    int men = 10000;
    for(int i = 0 ; i < n ; i++){
       cin>>ar[i];
       men = min(men , ar[i]);
    }

    for(int i = 1 ; i < n ; i++)
    {
        int dif = ar[i] - men;
        ar[i] -= dif;
        ar[0] += dif;
    }
   // cout<<ar[1]<<ar[0]<<"\n";
    bool flag = false;

    for(int i = 0 ; i <= 10000 ; i++)
    {
        if(ar[0] + (i * (n - 1)) == (ar[1] - i))
            flag = true;
        if(ar[0] - (i * (n - 1)) == (ar[1] + i))
            flag = true;
    }
    //cout<<flag<<"\n";
   // if(n == 1)cout<<1<<"\n";
     if(flag) cout<<n<<"\n"; else cout<<n - 1<<"\n";

    }
}
