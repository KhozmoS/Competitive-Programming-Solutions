#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pb push_back
#define db double
#define sz(c) (c).size()
#define all(c) (c).begin(),(c).end()

typedef long long ll;
typedef pair <int , int> ii;
typedef pair <ii , int> iii;
typedef vector <int> vi;
typedef vector < vi > vvi;
typedef vector < ii > vii;
typedef vector < vii > vvii;

const int mod = 1e9+7;
const int MAX = 1e6+5;

int freq[MAX];
int ans , res;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t = 4;
    while(t--)
    {
        int a , b , c;
        cin>>a>>b>>c;
        ans = max(a*2 + b*5 + c*7 , ans);

    }
    cout<<ans<<"\n";
}
