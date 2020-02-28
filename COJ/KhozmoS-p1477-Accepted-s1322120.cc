#include <bits/stdc++.h>

using namespace std;


int main ()
{
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t;cin>>t;
    while( t-- ) {
        int n;
        cin>>n;
        bool win = true;
        while ( true ) {
            if( n <= 9 && win) {
                break;
            } else if( n <= 2 ) {
                break;
            }

            if( win ) {
                n = n / 9 + ( n % 9 != 0 );
                win ^= true;
            } else {
                n = n / 2 + ( n % 2 != 0 );
                win ^= true;
            }
        }
        cout<<( win ? "Stan wins\n" : "Ollie wins\n" );
    }

}
