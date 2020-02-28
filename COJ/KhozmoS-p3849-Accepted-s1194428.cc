#include <bits/stdc++.h>

using namespace std;
const int MAX = 1e7+5;
bool mk[MAX];
int pr[1000005] , ac[1000005][11] , cnt;

void dec(int pos , int x)
{
    while(x)
    {
        ac[pos][x%10] = 1;
        x /= 10;
    }
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);

    for(int i = 2 ; i*i < MAX ; i ++)
        if(!mk[i])
        {
            for(int j = i*i ; j < MAX ; j += i)
                mk[j] = true;
        }
    for(int i = 2 ; i < MAX ; i++)
    {
        if(!mk[i])
            pr[++cnt] = i;
    }
    for(int i = 1 ; i <= cnt ; i++)
        dec(i , pr[i]);
    for(int d = 0 ; d <= 9 ; d++)
        for(int i = 1 ; i <= cnt ; i++)
            ac[i][d] += ac[i-1][d];
    int N;
    cin>>N;
    if(N <= 0)  return 0;

    while(N--)
    {
        int A , B , C;cin>>A>>B>>C;
        if(A > B) swap(A , B);
        int lo = lower_bound(pr+1 , pr+cnt+1 , A) - pr;
        int hi = upper_bound(pr+1 , pr+cnt+1 , B) - pr;
        lo--;
        hi--;
        cout<<ac[hi][C] - ac[lo][C]<<"\n";
    }
}
