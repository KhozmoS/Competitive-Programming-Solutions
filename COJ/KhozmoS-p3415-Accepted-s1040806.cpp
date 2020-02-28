#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        string imei;
        cin >> imei;

        int sum = 0;
        for(int i = 0; i < 14; i++)
        {
            if(i & 1){
                int x = (imei[i] - '0') * 2;
                x = (x % 10) + (x / 10);
                //cout << "X >> " << x << "\n";
                sum += x;
            }
            else
                sum += imei[i] - '0';
        }
        sum %= 10;
        if(sum > 0)
            sum = 10 - sum;

        cout << sum << "\n";
    }
    return 0;
}
