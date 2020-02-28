#include <bits/stdc++.h>

using namespace std;
const int MAX = 105; const int maxn = 1e4 * 2 + 3;
int ab[MAX] , ar[maxn];

void update(int pos , int val)
{
    for(int i = pos ; i < MAX ; i += (i & -i))
        ab[i] = max(ab[i] , val);
}
int query(int pos)
{
    int res = 0;
    for(int i = pos ; i > 0 ; i -= (i & -i))
        res = max(res , ab[i]);

    return res;
}

int main()
{

    int n; while(cin>>n)
    {
    for(int i = 1 ; i <= n ; i++) {cin>>ar[i];ar[i]++;}

    int ans1 = 0;
    for(int i = 1 ; i <= n ; i++)
    {
        int x = query(ar[i] - 1);
        if(ans1 < x + 1)
            ans1 = x + 1;
        update(ar[i] , x + 1);
    }
    memset(ab , 0 , sizeof(ab));
    int ans2 = 0;
    reverse(ar + 1 , ar + n + 1);
    for(int i = 1 ; i <= n ; i++)
    {
        int x = query(ar[i] - 1);
        if(ans2 < x + 1)
            ans2 = x + 1;
        update(ar[i] , x + 1);
    }
    memset(ab , 0 , sizeof(ab));
    if(ans1 == ans2) cout<<"Caution. I will not intervene.\n";
    else cout<<"Don't worry. I must intervene.\n";
}
    return 0;
}
