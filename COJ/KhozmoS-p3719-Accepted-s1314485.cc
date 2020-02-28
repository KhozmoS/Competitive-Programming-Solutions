#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pi pair<int, int>
#define vi vector<int>
#define vll vector<unsigned long long>
#define vd vector<double>
#define vp vector<pi>
#define vs vector<string>
#define qi queue<int>
#define qpi queue<pi>
#define sti set<int>
#define pb push_back
#define ll long long
#define ull unsigned long long
#define PI 3.141592653589793
#define mod 10000

const int MAX = 1e9;

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
            if(sm > MAX) break;
        }
        if (sm <= MAX)
            mp[sm]++;
    }

    cin >> q;
    while (q--)
    {
        cin >> qq;
        if(mp.find(qq) == mp.end())
            cout<<"0\n";
        else cout << mp[qq] << "\n";
    }
}

