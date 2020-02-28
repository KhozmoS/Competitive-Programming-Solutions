#include <bits/stdc++.h>

using namespace std;

long long A[55][55];

int in , fn;
int in1  = 00;
int fn1 = 00;
bool flag;
bool ans = false;
int main()
{
    int f , c;
    cin>>f>>c;

    for(int i = 1 ; i <= f ; i++)
       for(int j = 1 ; j <= c ; j++)
       {
         char x; cin>>x;
          if(x == '*')
          A[i][j] = 1 + ((A[i - 1][j] + A[i][j - 1] - (A[i - 1][j - 1])));
          else
          A[i][j] = (0 + (A[i - 1][j] + A[i][j - 1] - (A[i - 1][j - 1])));
       }
   // cout<<"wa\n";
  /* for(int i = 1 ; i <= f ; i++){
   for(int j = 1 ; j <= c ; j++)
     cout<<A[i][j];
     cout<<"\n";
     }*/
    for(int i = 1 ; i <= f ; i++)
       for(int j = 1 ; j <= c ; j++)
         for(int k = 0 ; k <= 50 ; k++)
         {
              if(i + k > f || j + k > c) break;
              int ar = 0, a = 0;
              do{
              a = ar;
              ar = (A[i + k][j + k] - A[i + k][j - 1] - A[i -1][j + k] + ((A[i-1][j-1])));
              k++;
              }
              while(ar == (k) * (k) && i + (k - 1) <= f && j + (k-1) <= c);
              //cout<<k<<" "<<a<<"\n";
             // cout<<k<<"\n";
              if(!a) break;
              ar = a;
              k--;
             int sq = sqrt(ar);
             int v = (k) * (k);
             //cout<<ar<<" "<<v<<"\n";
           //  cout<<v<<" "<<ar<<"\n";
              //cout<<sq<<"\n";
              if(in <= i && fn <= j && in1 >= i + k && fn1 >= j + k)
                continue;
              if(sq * sq == ar &&  ar == v)
              {

                 //cout<<"wa\n";
                 in = i;
                 fn = j;
                 fn1 = j + k;
                 in1 = i + k;
                 if(flag)
                   ans = false;
                 else
                 {
                   flag = true;
                   ans = true;
                 }
                 break;
              }
         }

   if(ans) cout<<"YES\n";

   else cout<<"NO\n";

}
