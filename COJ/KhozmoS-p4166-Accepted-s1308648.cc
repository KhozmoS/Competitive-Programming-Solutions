#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pb push_back
#define sz(c) (c).size()
#define all(c) (c).begin(),(c).end()
#define db double

typedef long long ll;
typedef pair <int,int> ii;
typedef pair <ii , int> iii;
typedef vector <int> vi;
typedef vector <ii> vii;
typedef vector <vi> vvi;
typedef vector <vii> vvii;

const int MAX = 1e6+5;



int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int mx = -INT_MAX;int mn = INT_MAX;
        int n;
        cin>>n;
        vii v(n+1,ii(0,0));

        for(int i = 1 ; i <= n ; i++)
            cin>>v[i].f>>v[i].s;
        sort(all(v));
        int ans = 0;
        for(int i = 1 ; i<= n;i++)
        {
            int a , b;
            a = v[i].f;
            b = v[i].s;
            int MX = b-a;
            int MN = b+a;
            //cout<<MN<<"\n";
            if(i!=1)
            {
                ans = max(mx-MX,ans);
                ans = max(MN-mn,ans);
            }
            mx = max(mx, MX);
            mn = min(mn,MN);
        }
        cout<<ans<<"\n";
    }

}
