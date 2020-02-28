#include<bits/stdc++.h>

using namespace std;
const int MAXN = 100005;
typedef pair<string , int> par;
 map<string , int > m;
 map<string , int > ::iterator it;
 string cad;
 int n;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    while(n--)
    {
        cin>>cad;
        sort(cad.begin() , cad.end());
        m[cad]++;
    }
     cout<<m.size()<<"\n";
    return 0;
}
