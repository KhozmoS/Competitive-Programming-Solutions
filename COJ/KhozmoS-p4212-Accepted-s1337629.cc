#include <bits/stdc++.h>

using namespace std;
const int MAX = 1e3+5;
int ar[MAX] , n , k;

set <char> s;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    string in;cin>>in;
    n = in.size();
    for(int i = 0 ; i < n ; i++) {
        s.insert(in[i]);
    }
    cin>>k;
    if( n < k ) {
        cout<<"NIE\n";
    }
    else {
        cout<<max( 0 , (int)k-(int)s.size() ) <<"\n";
    }
}
