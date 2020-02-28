#include <bits/stdc++.h>

using namespace std;
string cad;
int n;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    int w = n;
     while(n--)
     {
       cin>>cad;
       for(int i = 0 ; i < cad.size() ; i++)
        {
            if(i != cad.size() - 1){
           if(cad[i] == 'C' && cad[i + 1] == 'D')
            {
                w--; break;
            }
            }
        }
     }
     cout<<w<<"\n";
    return 0;
}
