#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define db double
#define pb push_back
#define sz(c) (c).size()
#define all(c) (c).begin(),(c).end()

typedef long long ll;
typedef pair <int , int> ii;
typedef pair <ii , int> iii;
typedef vector <int> vi;
typedef vector <ii> vii;
typedef vector <vi> vvi;
typedef vector <vii> vvii;

const ll mod = 1e9+7;
const int MAX = 1e6+7;
const db eps = 1e-13;

bool ok( int a , int b , int h , int p , db x ) {
    db A1 = (db)h * (a+b) / 2;
    int dif = b-a;
    db r = (db)dif/h;
    db B = r*x;
    B += a;
//    cout<<B<<"\n";
    db A2 = x * (a+B)/2;
    db P = (A2 * 100)/A1;
//    cout<<P<<"\n";
    return P<=p;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
    cout<<setprecision(6)<<fixed;
//    ok(1,2,45,56,28.668175);

    int t;cin>>t;
    while( t-- ) {

        int a , b , h , p;
        cin>>a>>b>>h>>p;
        db lo = 0; db hi = 0.000000001 + h;
        while( lo + eps < hi ) {
            db mt = (lo+hi)/2;
            if( ok(a , b , h , p , mt) ) {
                lo = mt;
            } else {
                hi = mt;
            }
        }
        db x = lo;
        int dif = b-a;
        db r = (db)dif/h;
        db B = r*x;
        B += a;
        cout<<x<<" "<<B<<"\n";
    }
}
