#include <bits/stdc++.h>

using namespace std;
vector<string>vc;
int m1 , m2;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    string cad;
    cin>>cad;
     int ta = cad.size();
     if(ta % 2 == 0)
        cout<<"error"<<"\n";
     else
    {
        vc.push_back(cad);
        cad[(ta / 2)] = ' ';
        //cout<<cad<<"\n";
         m1 = ta / 2 ;
         m2 = ta / 2 ;
         while( m1 != 0 && m2 != ta )
         {
             cad[m1] = ' ';cad[m2] = ' ';
             vc.push_back(cad);
            m1--;m2++;
         }
         int tv = vc.size();
         for(int i = 0 ; i < tv ; i++)
         {
             cout<<vc[i]<<"\n";
         }
         for(int i = tv - 2 ; i >= 0 ; i--)
         {
            cout<<vc[i]<<"\n";
         }
     }
    return 0;
}
