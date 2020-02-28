#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    
    string cad;
    cin>>cad;
    
    bool ans = false;
    
    for(int i = 0 ; i < cad.size() ; i++)
        if(cad[i] == 'i')
          ans = true;
      if(ans) cout<<"N\n";
      
      else
        cout<<"S\n";
    return 0;
}
