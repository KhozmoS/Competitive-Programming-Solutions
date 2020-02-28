#include <bits/stdc++.h>

using namespace std;
 map <string , int > m;
map <string , int > :: iterator it;
int t;
string cad;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>t;
    while(t -- )
    {
        cin>>cad;
        sort(cad.begin() , cad.end());
        cout<<m[cad]<<"\n";
        m[cad]++;
    }
    return 0;
}
