#include<bits/stdc++.h>


using namespace std;

const int MAX = 1e3+5;
#define PB push_back
#define db double




int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    db N , M;
    db ans = 0;
    cin>>N>>M;
   /* if(N-M==1)
    {
        cout<<setprecision(1)<<fixed<<N*(N-1)/2.0<<"\n";
        while(true);
        return 0;
    }*/
    ans += M-1;
    db R = N-M;
    if(R==1)
    {
         cout<<setprecision(1)<<fixed<<ans+1<<"\n";
         return 0;
    }
    R = (R*(R-1))/2.0;
    R/=((N-M-1));
    ans += R+0.5;

    cout<<setprecision(1)<<fixed<<ans<<"\n";
}
