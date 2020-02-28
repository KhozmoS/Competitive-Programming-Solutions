#include <bits/stdc++.h>

using namespace std;
const int MAXN = 1111111;


double TQ , a , b , c;
int t;
string cad;

int main()
{
//  ios_base::sync_with_stdio(0);cin.tie(0);

    //cout<<'Z' - 'a';
    cin>>t;
    int min = 0; int may = 0;
    cin>>cad;
    for(int i = 0  ; i < t ; i++)
    {
        if(cad[i] - 'a' >= 0) min++;
        else may ++;
    }
     cout<<may<<" "<<min<<"\n";
    return 0;
}
