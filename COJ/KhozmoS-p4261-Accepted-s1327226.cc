#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pb push_back
#define db double
#define sz(c) (c).size()
#define all(c) (c).begin(),(c).end()

typedef long long ll;
typedef pair < int , int > ii;
typedef pair < ii , int > iii;
typedef vector < int > vi;
typedef vector < ii > vii;
typedef vector < vi > vvi;
typedef vector < vii > vvii;

const ll mod = 1e9+7;
const int MAX = 1e6+5;



int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int ath , lfh , atm , lfm;
    cin>>lfh>>ath>>lfm>>atm;
    
    while( lfh > 0 && lfm > 0 ) {
        lfh -= atm;
        lfm -= ath;
    }
    if( lfh <= 0 && lfm <= 0 ) {
        cout<<"They will die as brothers\n";               
    } else if( lfh <= 0 ) {
        cout<<"The Mountain crush\n";
    } else {
        cout<<"The Hound will beat him\n";
    }


}
