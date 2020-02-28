#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
map <string , ll> mp;
map <string , bool > mk;
vector <string> v;
int n;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    sort(v.begin(), v.end());

    if (n == 2)
        cout << 0 << "\n";
    else
        cout << min(min(v[n-2] - v[0], v[n-1] - v[1]), v[n-1] - v[0]) << "\n";
}
