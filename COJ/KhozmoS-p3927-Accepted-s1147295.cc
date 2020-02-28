#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define MAXN 100005
#define endl '\n'

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef double db;
typedef pair<int,int> par;
//typedef tree < par, null_type, less<par>, rb_tree_tag, tree_order_statistics_node_update > tt;

const db eps = 1e-9, pi = acos(-1);

int n;
struct point {
    db x, y;
    point ( db xx = 0, db yy = 0): x(xx), y(yy) { }
    point operator - ( const point &p ) const {
        return { x-p.x, y-p.y };
    }
};

db dot ( const point &p, const point &q ) {
    return p.x * q.x + p.y * q.y;
}

db abs ( const point &p ) {
    return sqrt ( dot ( p, p ) );
}

struct building {
    db x, h;
    bool operator < ( const building &b ) const {
        return x+eps < b.x;
    }
}b[MAXN];

bool check ( db x, db r ) {
    for ( int i = 1; i <= n; i ++ ) {
        if ( abs( point(x,0) - point(b[i].x-0.5, b[i].h)) - eps > r )
            return false;
        if ( abs( point(x,0) - point(b[i].x+0.5, b[i].h)) - eps > r )
            return false;
    }
    return true;
}

db find_x ( db r ) {
    db sol = 1e9;
    for ( int i = 1; i <= n; i ++ ) {
        db ini = b[i].x - 0.5, fin = (sol==1e9)?1e7:sol, piv;
        while ( ini+eps < fin ) {
            piv = (ini+fin)/2.0;
            if ( abs( point(piv,0) - point(b[i].x-0.5, b[i].h ) ) - eps > r )
                fin = piv;
            else
                ini = piv;
        }
        sol = min (sol, ini );
    }
    return sol;
}


int main() {
    /*#ifdef acm
        freopen ("a.in", "r", stdin );
    #endif // acm*/
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    db ini, fin = 1e9, piv;
    for ( int i = 1; i <= n; i ++ ) {
        cin >> b[i].x >> b[i].h;
        ini = max ( ini, b[i].h );
    }
    sort ( b+1, b+1+n );

    while ( ini+eps < fin) {
        piv = (ini+fin)/2.0;
        db x = find_x ( piv );
        if ( check ( x, piv ) )
            fin = piv;
        else
            ini = piv;
    }
    cout << fixed << setprecision(10) << ini;

    return 0;
}
