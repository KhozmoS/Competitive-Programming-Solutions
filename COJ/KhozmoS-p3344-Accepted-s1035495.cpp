#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        int cases;
        cin >> cases;

        int num, prev, sol = 0;
        cin >> num;
        prev = num;
        for(int i = 1; i < 15; i++)
        {
            cin >> num;
            if(num > prev)
                sol++;
            prev =  num;
        }
        cout << cases << " " << sol << "\n";
    }
}
