#include <bits/stdc++.h>

using namespace std;
string cad;
string comp;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>cad;
    if(next_permutation(cad.begin(),cad.end()))
    cout<<cad;
    else
    cout<<0<<"\n";


    return 0;
}
