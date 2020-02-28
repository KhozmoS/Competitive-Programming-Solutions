#include <bits/stdc++.h>

using namespace std;


int n, q, qq, sm;
int cj[20];
map<int, int> mp;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> cj[i];

    for (int i = 0; i<(1<<n); i++)
    {
        sm = 0;
        for (int j = 0; j < n; j++)
        {
            if (i&(1<<j))
                sm += cj[j];
           if(sm>1000000000)break;
        }
       if(sm<=1000000000)
        mp[sm]++;
    }

    cin >> q;
    while (q--)
    {
        cin >> qq;
        if(mp.find(qq)==mp.end())
             cout<<"0\n";
        else
              cout << mp[qq] << "\n";
    }
}
