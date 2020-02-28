#include<bits/stdc++.h>


using namespace std;
vector <int> A;
const int MAXN = 255;
char cad[MAXN] , tet[MAXN];
char c; int sol;
int cant;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    //getline(cin, cad);
   // cout<<cad;
   while(cin>>n)
   {
      // if(n == 0) break;
       cant++;
       A.push_back(n);
       int ind = cant - 1;
       ind--;
       while(ind >= 0)
       {
           if(__gcd(A[cant - 1] , A[ind]) > sol)
           sol = __gcd(A[cant - 1] , A[ind]);
           ind--;
       }
   }
   cout<<sol<<"\n";
    return 0;
}
