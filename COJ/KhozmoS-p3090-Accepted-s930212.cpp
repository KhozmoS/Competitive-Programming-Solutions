#include <bits/stdc++.h>

using namespace std;

int lad[4];

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>lad[0]>>lad[1]>>lad[2];
    sort(lad , lad + 3);
  //  cout<<lad[0]<<lad[1]<<lad[2];
     if(lad[2] * lad[2] == (lad[0] * lad[0]) + (lad[1] * lad[1]))
     cout<<"rectangulo\n";
     else if(lad[2] * lad[2] > (lad[0] * lad[0]) + (lad[1] * lad[1]))
     cout<<"obtusangulo\n";
     else
     cout<<"acutangulo\n";
    return 0;
}
