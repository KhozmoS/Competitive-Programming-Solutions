#include <bits/stdc++.h>

using namespace std;
const int MOD = 1000000007;
const int MAXN = 3005;

int P[MAXN][MAXN];

void PASCAL()
{
  P[0][0] = 1;
  for(int i = 1 ; i < MAXN ; i++)
  for(int j = 1 ; j <= i ; j++){
  P[i][j] = (((P[i - 1][j - 1] % MOD) + (P[i - 1][j] % MOD)) % MOD);
  }
}
int porgustavo;

int main()
{
   ios_base::sync_with_stdio(0);cin.tie(0);
    //  memset(D , -1 , sizeof(D));
    //cout<<__gcd(5 , 5);
    PASCAL();


  int t;

    cin>>t;

    while(t--)
    {
      int N , n;
      cin>>N;
      int sum = 0;
      bool flag = false;
      int k = 0;
      for(int i = 0 ; i < 18 ; i++)
      {
        sum += pow(2 , i);
        int talla = N - sum;
        int cosita = pow(2 , i + 1);
        if(talla < cosita && talla != 0){
        k = talla;
        n = cosita;
        break;
        }
        if(!talla)
        {
         cout<<"0\n";
         goto END;
        }
      }
      //cout<<n<<" "<<k<<" ";
       cout<<(P[n + 1][k + 1] - 1 + MOD) % MOD <<"\n";
       END:
       porgustavo++;
    }

    return 0;
}
