#include <bits/stdc++.h>

using namespace std;

#define AreaS(R) 4 * 3.14159 * R * R * R / 3
#define AreaC(R , H) 3.14159 * R * R * H / 3
#define AreaL(R , H) 3.14159 * R * R * H

string cad ;
int n;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n;

  while(n--)
  {
      cin>>cad;
      for(int i = 0 ; i < cad.size() ; i++)
          (islower(cad[i]) ? cad[i] = toupper(cad[i]) : cad[i] = tolower(cad[i]));

      cout<<cad<<"\n";
  }
    return 0;
}
