#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
const int MAXN = 100005;

 string cad;

 vector <int> A[MAXN];
 int sol[MAXN];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
     cin>>t;

     while(t--)
     {
         int n;

         cin>>n>>cad;

         for(int i = 0 ; i < n - 1 ; i++)
         {
             bool flag = false;
             int sols = -1;
             for(int j = i + 1 ; j < n ; j++)
             {
                 if(cad[i] < cad[j])
                 {
                     flag = true;
                     sols = j + 1;
                     break;
                 }
             }
             sol[i + 1] = sols;

         }
         sol[n] = -1;
         for(int i = 1 ; i < n ; i++)
         cout<<sol[i]<<" ";
         cout<<sol[n]<<"\n";
     }


    return 0;

}
