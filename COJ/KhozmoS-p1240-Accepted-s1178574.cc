#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e6 + 5;

int n , k;
bool mk[MAX];


int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    while(cin>>n>>k && n)
    {
        int ar[k+3];

        memset(mk , false , sizeof(mk));
        for(int i = 1 ; i <= k ; i++)
            cin>>ar[i];

        for(int i = 1 ; i <= k ; i++)
            for(int j = i+1 ; j <= k ; j++)
            {
                mk[ar[i]] = true;
                mk[ar[j]] = true;
                mk[abs(ar[i] - ar[j])] = true;
            }
        int ans = 0;
        for(int i = 0 ; i <= n ; i++)
            ans += mk[i];

        cout<<(ans==n+1 ? "Y\n" : "N\n");
    }

}
