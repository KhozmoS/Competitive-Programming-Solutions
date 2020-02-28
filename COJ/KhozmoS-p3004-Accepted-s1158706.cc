#include <bits/stdc++.h>

using namespace std;


#define pos first
#define col second

typedef long long ll;

const int MAX = 1e5 + 5;
map <int  , int> M;

typedef pair <int , char> cow;
cow v[MAX];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;cin>>n;

    for(int i = 0 ; i < n ; i++)
        cin>>v[i].pos>>v[i].col;

    sort(v , v+n);
    int ans = 0;
    M[0] = -1;
    int cur = 0;

    for(int i = 0 ; i < n ; i++)
    {
        if(v[i].col == 'W') cur++;
        else cur--;
        if(cur <= 0){
        if(M.find(cur) != M.end())
            ans = max(ans , v[i].pos - v[M[cur]+1].pos);

        if(M.find(cur - 2) != M.end())
            ans = max(ans , v[i].pos - v[M[cur-2]+1].pos);
        }
        else{
            if(cur & 1){
             if(M.find(1) != M.end())
               ans = max(ans , v[i].pos - v[M[1]+1].pos);

            if(M.find(-1) != M.end())
              ans = max(ans , v[i].pos - v[M[-1]+1].pos);
            }
            else ans = max(ans , v[i].pos - v[0].pos);
        }

        if(M.find(cur) == M.end())
            M[cur] = i;
    }

    cout<<ans<<"\n";
}
