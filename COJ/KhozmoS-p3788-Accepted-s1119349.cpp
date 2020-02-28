#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int m = 10;
const int MAX = 1005;
int A[MAX] , B[MAX] , C[MAX] , S[MAX][10][10][10];

int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);

   for(int a = 0 ; a <= 9 ; a++)
        for(int b = 0 ; b <= 9 ; b++)
             for(int c = 0 ; c <= 9 ; c++){
                 A[0] = a;
                 B[0] = b;
                 C[0] = c;
                 for(int i = 1 ; i <= 1000 ; i++)
                 {
                   C[i] = (B[i - 1] - A[i - 1] + m) % m;
                   B[i] = (((5 * A[i - 1]) % m) - ((4 * B[i - 1]) % m) + m) % m;
                   B[i] = (B[i] - ((4 * C[i - 1]) % m) + m) % m;

                   A[i] = (((4 * A[i - 1]) % m) - ((3 * B[i - 1]) % m) + m) % m;
                   A[i] = (A[i] - ((3 * C[i - 1]) % m) + m) % m;

                   S[i][a][b][c] = S[i - 1][a][b][c] + A[i] + B[i] + C[i];
                   S[i][a][b][c] %= m;
                 }
             }
      int t;cin>>t;
          while(t--)
          {
             unsigned long long n;
             int a , b , c;
             cin>>n>>a>>b>>c;
             int cic = 0;
             for(int i = 10 ; i < 1000 ; i++)
             {
                 if(S[cic][a][b][c] == S[i][a][b][c])
                 {
                    int k = i;
                    while(cic < i && S[cic][a][b][c] == S[k][a][b][c] && k < 1000)
                    {
                        cic++;
                        k++;
                    }
                 }
                 if(cic == i)
                    break;
                 else
                    cic = 0;
             }
             cout<<S[n % (unsigned long long)cic][a][b][c]<<"\n";
          }

   return 0;
}
