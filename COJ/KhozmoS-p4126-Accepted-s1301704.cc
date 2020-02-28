#include <bits/stdc++.h>

using namespace std;
const int MAX = 1e6;
vector <int> p;
bool mk[MAX];
int arr[505][505];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n , m;cin>>n>>m;
    for(int i = 2 ; i * i < MAX ; i++)
        if(!mk[i])
            for(int j = i * i ; j < MAX ; j += i)
                mk[j] = true;
    for(int i = 2 ; i < MAX ; i++)
        if(!mk[i]){
            p.push_back(i);
        }
    int ans = INT_MAX;
    for(int i = 1 ; i <= n ; i++){
        int cnt = 0;
        for(int j = 1 ; j <= m ; j++){
            cin>>arr[i][j];
            int pos = lower_bound(p.begin(),p.end(),arr[i][j]) - p.begin();
            cnt += p[pos]-arr[i][j];

        }
        ans = min(cnt , ans);
    }
    for(int j = 1 ; j <= m ; j++)
    {
        int cnt = 0;
        for(int i = 1 ; i <= n ; i++)
        {
            int pos = lower_bound(p.begin(),p.end(),arr[i][j]) - p.begin();
            cnt += p[pos]-arr[i][j];
        }
        ans = min(cnt , ans);
    }
    cout<<ans<<"\n";
}
