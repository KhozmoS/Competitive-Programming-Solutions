#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000000000;
const int MAXN = 1111;

string cad;
int r , f , m;
int mr , mf , mm;
int main()
{

  ios_base::sync_with_stdio(0);cin.tie(0);
   cin>>cad;

   for(int i = 0 ; i < cad.size() ; i++)
   {
       if(cad[i] == 'R')
       r++;
       if(cad[i] == 'M')
       m++;
       if(cad[i] == 'F')
       f++;
       if(mr < r)
       {
           mr = r;
       }
       if(cad[i] != 'R') r = 0;

       if(mm < m )
       {
           mm = m;
       }
       if(cad[i] != 'M') m = 0;
       if(mf < f)
       {
           mf = f;
       }
       if(cad[i] != 'F') f = 0;

   }
   if(mr >= mf && mr >= mm)
   cout<<mr<<" Rat\n";
   else if(mm >= mf)
   cout<<mm<<" Milk\n";
   else
   cout<<mf<<" Fish\n";

    return 0;
}//MMFRRMFMFMRRFFMM
