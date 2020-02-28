#include <bits/stdc++.h>

using namespace std;

map <int , int> mk;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int best = 0 , last = 0;
        for(int i = 1 ; i <= n ; i++)
        {
             int x;
             cin>>x;
             if(mk.find(x) == mk.end())
             {
                 best = max(best , min(i , i - last));
             }
             else{
                 last = max(last , mk[x]);
                 best = max(best , i - last);
             }
                 mk[x] = i;
        }
        cout<<best<<"\n";
        mk.clear();
    }
}
