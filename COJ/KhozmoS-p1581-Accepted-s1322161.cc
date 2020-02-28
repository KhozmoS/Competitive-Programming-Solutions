#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e6;


#define f first
#define s second
#define pb push_back
typedef pair < int , int > ii;
vector < ii > Q;
int B , S , L , R;
int soldierL[MAX];
int soldierR[MAX];

string toString( int x ) {
    string res = "";
    while( x )
    {
        res = char( ( x%10 ) + 48 ) + res;
        x /= 10;
    }
    return res;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    for( int i = 1 ; i <= MAX ; ++i ) {
        soldierL[i] = i-1;
        soldierR[i] = i+1;
    }

    while( cin>>S>>B && S ) {
        while( B-- ) {
            cin>>L>>R;
            soldierL[soldierR[R]] = soldierL[L];
            soldierR[soldierL[L]] = soldierR[R];
            Q.pb( ii( L , R ) );
            cout<<( soldierL[L] ? toString( soldierL[L] ) : "*" )<<" "<<( soldierR[R] <= S ? toString( soldierR[R] ) : "*" )<<"\n";
        }
        for( int i = 0 ; i < Q.size() ; ++i ) {
            soldierL[Q[i].f] = Q[i].f - 1;
            soldierR[Q[i].f-1] = Q[i].f;
            soldierR[Q[i].s] = Q[i].s + 1;
            soldierL[Q[i].s+1] = Q[i].s;
        }
        cout<<"-\n";
    }
}
