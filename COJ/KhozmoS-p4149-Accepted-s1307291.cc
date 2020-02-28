#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define sz(c) (c).size()

typedef long long ll;
typedef pair<int , int > ii;
typedef vector <int> vi;

const ll mod = 1e9+7;
const int MAX = 1e6+7;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        bool ok = false;
        int cur = 1;
        while(n)
        {
            if(cur&1)
            {
                if(n&1)
                {
                    cout<<"NIE\n";
                    break;
                }
                else n/=2;
            }
            else{
                if(n&1)
                {
                    cout<<"TAK\n";
                    break;
                }
                else n/=2;
            }
            cur++;
        }
    }
}
