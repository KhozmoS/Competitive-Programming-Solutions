#include <bits/stdc++.h>

using namespace std;
const int MAX = 1e3+5;
int ar[MAX] , n , s;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n>>s;
    for( int i = 0 ; i < n  ; i++ ) cin>>ar[i];
    for( int i = 0 ; i < n ; i ++ )
        for ( int j = i+1 ; j < n ; j++ )
            for ( int k = j + 1 ; k < n ; k++ )
                if( ar[i] + ar[j] + ar[k] == s ) {
                    cout<<"TAK\n";
                    return 0;
                }
    cout<<"NIE\n";


}
