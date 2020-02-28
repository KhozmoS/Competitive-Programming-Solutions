#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair <int , int> II;
typedef vector <int> VI;
typedef vector <II> VII;

#define PB push_back
#define f first
#define s second

const int mod = 1000007;
const int MAX = 1e6 + 5;
int Fib[MAX] , P[1005][1005];
map <int , int> mk;

void PASCAL()
{
    for(int i = 0 ; i < 1005 ; i++)
        for(int j = 0 ; j <= i ; j++)
           if(i == j || !j) P[i][j] = 1;
           else
              P[i][j] = (P[i-1][j-1] + P[i-1][j]) % mod;
}
int KT(int n)
{
    return (P[2*n][n] - P[2*n][n+1] + mod) % mod;
}

int main()
{
   // cout<<FIB(6)<<"\n";
    PASCAL();
    ios_base::sync_with_stdio(0);cin.tie(0);
    Fib[0] = 0;
    Fib[1] = 1;
    for(int i = 2 ; i < MAX ; i++){ Fib[i] = (Fib[i-1] + Fib[i-2])%mod;
    }
    Fib[0]++;
    for(int i = 1 ; i < MAX ; i++)
    {
        Fib[i] += Fib[i-1];
        Fib[i] %= mod;
    }

   /* int cont = 0;bool flag = false;
    for(int i = 0 ; i < MAX; i++){// if(!flag)cout<<Fib[i]<<"\n";//cout<<Fib[i]-Fib[i-1]<<"\n";}
    if(mk.find(Fib[i]) != mk.end()){
        // cout<<"here : "<<i<<" "<<Fib[i]<<" "<<mk[Fib[i]]<<"\n";
         flag = true;
         if(Fib[i] == 1 && Fib[i+1] == 2){
             int c = 0;
             for(int j = i ; c <= 10 ; j++){
                cout<<Fib[j]<<" "<<j<<"\n";
                c++;
             }
          return 0;
         }
    }
      if(mk.find(Fib[i]) == mk.end())
        mk[Fib[i]] = i;


    }*/
    int t;ll n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        cout<<Fib[(n%482776)]<<"\n";
    }
    //for(int i = 0 ; i < 20 ; i++)cout<<KT(i)<<"\n";
}
//482776
