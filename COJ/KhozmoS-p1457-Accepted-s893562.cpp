#include <bits/stdc++.h>

using namespace std;
 long long sol,n,k;
int main()
{
    cin>>n>>k;
    for(int i = n - 1 ;i > 0 ;i--)
    {
        sol += i * k;
    }
    cout<<sol<<endl;
    return 0;
}
