#include <bits/stdc++.h>

using namespace std;
const int MAXN = 55;

int n;
int ar[MAXN];
int t;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>t;

    while(t--)
    {
        cin>>n;
        bool flag = false;

        for(int i = 0 ; i < n ; i++)
        {
            cin>>ar[i];
            int sum = ar[i];
            if(sum == 0)
            flag = true;
            for(int j = i - 1 ; j >= 0 ; j--)
            {
              sum += ar[j];

              if(sum == 0)
              flag = true;
            }

        }
        if(flag) cout<<"YES\n";

        else cout<<"NO\n";

    }


    return 0;
}
//1 6 2 3 5
