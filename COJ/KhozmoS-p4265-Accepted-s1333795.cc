#include <bits/stdc++.h>

using namespace std;


#define f first
#define s second
#define pb push_back
#define db double
#define sz(c) (c).size()
#define all(c) (c).begin(),(c).end()

typedef long long ll;
typedef pair <int , int > ii;
typedef pair <ii , int > iii;
typedef vector <int> vi;
typedef vector <ii> vii;
typedef vector <vi> vvi;
typedef vector <vii> vvii;

const ll mod = 1e9+5;
const int MAX = 1e5+5;



// B < D*2 | D < C*2 | C < B*2

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;cin>>t;
    while(t--) {
        int a ,b;
        cin>>a>>b;
//        cout<<pot5[b-a]<<"\n";
        if( a > b ) {
//            cout<<pot2[a-b]<<" "<<a-b<<"\n";
            cout<<(b + 1 + floor((a-b) * (log10(2))))<<"\n";
        }else {
            cout<<(a + 1 + floor((b-a) * (log10(5))))<<"\n";
        }
    }
}
