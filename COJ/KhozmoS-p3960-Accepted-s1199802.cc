#include <bits/stdc++.h>

using namespace std;
const int MAX = 1e6;

string cad;
int U , D , L , R;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>cad;int sz = cad.size();
    if(sz&1){cout<<"-1\n";return 0;}
    int X = 0;
    int Y = 0;
    for(int i = 0 ; i < sz ; i++)
    {
        if(cad[i] == 'U') Y++;
        if(cad[i] == 'D') Y--;
        if(cad[i] == 'R') X++;
        if(cad[i] == 'L') X--;
    }
     cout<<(abs(X) + abs(Y))/2<<"\n";

}
