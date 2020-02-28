#include <bits/stdc++.h>

using namespace std;
string cad;
int sol , ta;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    while(1)
    {
        cin>>cad;
        if(cad == "END")
        break;

        ta = cad.size();
        for(int i = ta - 1 ; i >= 0 ; i--)
        {
            if(cad[i] != '0')
            {
              cad[i]--;
              break;
            }
        }
        bool flag = 0;
        string sol = "";
        int cont = 0;
        for(int i = 0 ; i < ta ; i++)
        {
            if(cad[i] != '0')
            {
                flag = true;
                sol += cad[i];
            }
            else if(flag)
            {
                sol += cad[i];
            }
            else
            {
               if(cont == 0){
               sol += cad[i];
               cont++;
               }
            }

        }
        cout<<sol<<"\n";
    }
    return 0;
}
