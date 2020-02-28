#include <bits/stdc++.h>

using namespace std;


map <string , int> mapa;
const int MAXN = 200005;
string ar[MAXN];

int n;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    string x;
    for(int i = 0 ; i < (2 * n) - 1 ; i++)
    {
        cin>>x;
        ar[i] = x;
        mapa[x]++;
    }

    for(int i = 0 ; i < (2 * n) - 1 ; i++)
    if(mapa[ar[i]] % 2){
    cout<<ar[i]<<"\n";
    return 0;
    }
    return 0;
}
