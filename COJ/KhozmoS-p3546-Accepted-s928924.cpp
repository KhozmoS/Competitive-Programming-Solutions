#include <bits/stdc++.h>
#define MAXN 1000000
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    double N , p , c;
    double men = 1001;
    cin>>N;
    int cont = 1;
    int sol;
    while(N--)
    {
       cin>>p>>c;
       if(men > p / c)
       {
          men = p / c;
          sol = cont;
       }
       cont++;
    }
    cout<<sol<<"\n";

    return 0;
}
