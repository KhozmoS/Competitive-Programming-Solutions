#include <bits/stdc++.h>

using namespace std;
const int MAX = 1e5+5;
int ar[MAX];
vector <string> RI;
vector <string> DRI;
vector <string> DI;

int n , l , c;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);

     cin>>n>>l>>c;

     for(int i = 1 ; i <= n ; i++)
        cin>>ar[i];
    sort(ar + 1 , ar + 1 + n);
    int i = n;
    while(i >= 1)
    {
      c -= ar[i];
      i -= l;
    }
    if(c < 0) cout<<"N\n";
    else cout<<"S\n";
    return 0;
}
