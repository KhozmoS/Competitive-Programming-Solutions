#include <bits/stdc++.h>

using namespace std;

int n , s , ans_min = 1000000, ans_max = 0;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n>>s;
    for(int c = 0; c <= 10000 ; c++)
        for(int mn = 1 ; mn <= n ; mn++)
        {
            int mx = n-mn;
            if((mn*c + (mx * (c+1))) == (s+c))
            {
                //cout<<c<<" "<<mn<<" "<<mx<<"\n";
                ans_min = min(ans_min , s+c);
                ans_max = max(ans_max , s+c);
            }
        }
    cout<<ans_min<<" "<<ans_max<<"\n";
}
