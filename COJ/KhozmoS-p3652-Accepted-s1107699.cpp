#include <bits/stdc++.h>

using namespace std;

string cad;
int t;
bool flag;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);


    cin>>t;


       while(t--)
       {
           flag = false;
           cin>>cad;

           if(cad[0] == '1')
           flag = true;

           for(int i = 1 ; i < cad.size() ; i++)
           if(cad[i] != '0')
           {
               flag = false;
               break;
           }
        cout<<flag<<"\n";
       }
    return 0;
}
