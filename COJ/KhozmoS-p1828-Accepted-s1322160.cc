#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e6;
int T;
double A , B , L  , R;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>T;
    while( T-- ) {
        cin>>A>>B>>L>>R;
        if( L < R ) {
            cout<<"L\n";
        } else if ( L > R ){
            cout<<"R\n";
        } else {
            cout<<"T\n";
        }
    }
}

