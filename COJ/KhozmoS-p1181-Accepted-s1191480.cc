#include <bits/stdc++.h>

using namespace std;

int fem , mal;

int main()
{
   ios_base::sync_with_stdio(0);cin.tie(0);
   int n;
   while(cin>>n && n != -1){

   fem = 1;
   mal = 0;
   int i = 1;
   while(i <= n)
   {
       int nmal = mal + fem;
       int nfem = mal + 1;
       mal = nmal;
       fem = nfem;
       i++;
   }
   cout<<mal<<" "<<fem+mal<<"\n";
   }
}
