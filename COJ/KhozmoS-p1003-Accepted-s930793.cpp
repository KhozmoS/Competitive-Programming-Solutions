#include <iostream>

using namespace std;
const int MAXN = 105;
int vot[MAXN][MAXN];
int main()
{
//    cout << "Hello world!" << endl;
   int t;
   cin>>t;
   while(t--)
   {
       int n , m;
       cin>>n>>m;
       for(int i = 1 ; i <= m ; i++)
       for(int j = 1 ; j <= n ; j++)
       cin>>vot[i][j];
       int sum = 0 , may = -1;int pos;
       for(int j = 1 ; j <= n ; j++){
       for(int i = 1 ; i <= m ; i++){
         sum += vot[i][j];
       }
       if(sum >= may)
       {
           may = sum;
           pos = j;
       }
       sum = 0;
       }
       cout<<pos<<"\n";
   }

    return 0;
}
