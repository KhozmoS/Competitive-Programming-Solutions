#include<bits/stdc++.h>

using namespace std;
const int MAXN = 105;

int N;
int MA[MAXN][MAXN] , TA[MAXN][MAXN];

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
   cin>>N;
   for(int i = 1 ; i <= N ; i++)
   for(int j = 1 ; j <= N ; j++){
    cin>>MA[i][j];
    TA[i][j] = ((TA[i - 1][j] + TA[i][j - 1]) - TA[i - 1][j - 1]) + MA[i][j];
   }
   int summ = -100000000;
   for(int i = 1 ; i <= N ; i++){
   for(int j = 1 ; j <= N ; j++)
   {
    for(int ii = i ; ii <= N ; ii++){
    for(int jj = j ; jj <= N ; jj++){
      if(ii != i && jj != j)
      {
        int comp = ((TA[ii][jj] - TA[i - 1][jj]) - TA[ii][j - 1]) + TA[i - 1][j - 1];
        if(summ < comp)
        {
            summ = comp;
        }
      }
    }
    }
   }
   }
     cout<<summ<<"\n";
    return 0;
}
