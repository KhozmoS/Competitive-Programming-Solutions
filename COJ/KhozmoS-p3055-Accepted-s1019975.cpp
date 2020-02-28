#include <bits/stdc++.h>

using namespace std;
const int MAXN = 1111111;
long long sol = 1;

long long ar[30];


int main() {

 ios_base::sync_with_stdio(0);cin.tie(0);
   int t;
   cin>>t;
   string cad;
   for(int i = 0 ; i < 26 ; i++){
       if(i == 0 || i == 4 || i == 8 || i == 14 || i == 18)
       ar[i] += 3;
       else
       ar[i] += 2;
       }
       //0123456789 10 11 12 13 14 15 16 17 18
     //  for(int i = 0 ; i < )
   while(t--)
   {
       cin>>cad;

       for(int i = 0 ; i < cad.size() ; i++)
       {
           if(cad[i] >= '0' && cad[i] <= '9')
           sol *= 3;
           else if(islower(cad[i]))
           sol *= ar[cad[i] - 'a'];
           else
           sol *= ar[cad[i] - 'A'];
       }
       cout<<sol<<"\n";
       sol = 1;
   }
	return 0;
}
