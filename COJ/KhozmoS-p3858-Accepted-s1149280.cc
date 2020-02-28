#include <bits/stdc++.h>
#define endl '\n'
#define maxn 40005

using namespace std;

typedef long long ll;
typedef pair <int,int> par;

int n;
struct r{
    int x, y, id;
}G[100005], nG[100005];

int A[100005];
int B[100005];

bool comp( const r s1, const r s2 ){
    if( s1.x != s2.x )
        return s1.x < s2.x;
    return s1.y < s2.y;
}

bool comp1( const r s1, const r s2 ){
    if( s1.y != s2.y )
        return s1.y < s2.y;
    return s1.x < s2.x;
}

int sol[100005];

int Dp[1000005], my, mx;
void add( int x ){
    for( ; x <= my; x += (x&-x) )
        Dp[x] ++;
}
int sum( int x ){
    int s = 0;
    for( ; x; x -= (x&-x) )
        s += Dp[x];
    return s;
}
///--------x

int vx[1000005];
void addx( int x, int w ){
    for( ; x <= mx; x += (x&-x) )
        vx[x] = max( w, vx[x] );
}
int mayx( int x ){
    int s = 0;
    for( ; x; x -= (x&-x) )
        s = max(s, vx[x]);
    return s;
}
///---------y
int vy[1000005];
void addy( int x, int w ){
    for( ; x <= my; x += (x&-x) )
        vy[x] = max( w, vy[x] );
}
int mayy( int x ){
    int s = 0;
    for( ; x; x -= (x&-x) )
        s = max(s, vy[x]);
    return s;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for ( int i = 1; i <= n; i ++ ) {
        cin >> G[i].x >> G[i].y;
        G[i].id = i;
        A[i] = G[i].x;
        B[i] = G[i].y;

        nG[i] = G[i];
        my = max( my, G[i].y );
        mx = max( mx, G[i].x );
    }

    for( int i = 1; i <= n; i ++ ){
        addx( G[i].x, G[i].y );
        addy( G[i].y, G[i].x );
    }

    for( int i = 1; i <= n; i ++ ){
        int ay = mayx( nG[i].x-1 );
        int bx = mayy( nG[i].y-1 );
        while( nG[i].x < bx || nG[i].y < ay ){
            int t1 = nG[i].x;
            int t2 = nG[i].y;

            addx( t1, ay );
            addy( t2, bx );

            nG[i].x = max( nG[i].x, bx);
            nG[i].y = max( ay, nG[i].y );

            ay = mayx( nG[i].x-1 );
            bx = mayy( nG[i].y-1 );
        }
    }

    for( int i = 1; i <= n; i ++ ){
        if( G[i].x < nG[G[i].id].x || G[i].y < nG[G[i].id].y )
            sol[G[i].id] --;
    }

    sort( nG+1, nG+1+n, comp );
    sort( G+1, G+1+n, comp );

    sort( A+1, A+1+n );
    sort( B+1, B+1+n );

    int a;
    for( int i = 1; i <= n; i ++ ){
        a = lower_bound( A+1, A+1+n, nG[i].x ) - A-1;
        sol[nG[i].id] += a;
        a = lower_bound( B+1, B+1+n, nG[i].y ) - B-1;
        sol[nG[i].id] += a;
    }

    int t = 1;
    for( int i = 1; i <= n; i ++ ){
        while( t <= n && nG[t].x <= G[i].x ){
            sol[nG[t].id] -= sum( nG[t].y-1 );
            t ++;
        }

        add( G[i].y );
    }

    while( t <= n ){
            sol[nG[t].id] -= sum( nG[t].y-1 );
            t ++;
    }

    for( int i = 1; i <= n; i ++ )
        cout << sol[i] << endl;


    return 0;
}
