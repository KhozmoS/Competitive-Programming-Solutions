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
    int n;cin>>n;
    while(n--) {
        int x;
        cin>>x;
        freq[x]++;
    }
    for(int i = 0 ; i <= 1001 ; ++i)
    {
        ans += freq[i]/4;
        res += freq[i]%4;
    }
    cout<<ans<<" "<<res<<"\n";
}
