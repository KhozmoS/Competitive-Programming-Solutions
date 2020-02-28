#include <bits/stdc++.h>

using namespace std;




int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);

    long long k , n , w;
    cin>>k>>n>>w;
    long long cnt = 0;
    cnt += k*(w*(w+1)/2);
    cout<<max(0ll,cnt-n)<<"\n";
}
