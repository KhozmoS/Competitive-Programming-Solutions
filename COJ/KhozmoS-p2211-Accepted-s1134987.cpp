#include <bits/stdc++.h>

using namespace std;

int t;
string cad;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>t;


    while(t--)
    {
        int a = 0; int g = 0;
        cin>>cad;
        bool flag;
        if(cad[0] == 'A') flag = true , a++;
        else flag = false , g++;

        for(int i = 0 ; i < cad.size() ; i++)
        {
          if(flag && cad[i] == 'G')
          {
              flag = false;
              g++;
          }
          else if(!flag && cad[i] == 'A')
          {
              flag = true;
              a++;
          }
        }
        if(a >= g && a || !g) cout<<"Alf\n";
        else cout<<"Gustav\n";
        a = 0;
        g = 0;
    }

    return 0;
}
