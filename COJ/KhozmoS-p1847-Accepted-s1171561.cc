#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define x first
#define y second

const int MAX = 1e3 * 2 + 5;
typedef pair <ll , ll> point;
point ar[MAX];

ll sq(ll a)
{
    return a * a;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);

    int n;
    cin>>n;

    for(int i = 0 ; i < n ; i++) cin>>ar[i].x>>ar[i].y;

    int ans1 , ans2;
    ll best = 1000000000000ll;
    for(int i = 0 ; i < n ; i++)
        for(int j = i+1 ; j < n ; j++)
           if(sq(ar[i].x - ar[j].x) + sq(ar[i].y - ar[j].y) < best)
            {
                best = sq(ar[i].x - ar[j].x) + sq(ar[i].y - ar[j].y);
                ans1 = i;
                ans2 = j;
            }
     if(n==1)while(true);
     cout<<ans1+1<<" "<<ans2+1<<"\n";
}
