#include <bits/stdc++.h>

using namespace std;
const int MAXN = 2222222;

int sol , n , x;
int freq[MAXN];
int mk[MAXN];
int ar[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);

      cin>>n;
      for(int i = 0 ; i < n ; i++)
      {
          cin>>ar[i];
          freq[ar[i]]++;
          mk[ar[i]] = true;
      }
          cin>>x;

          for(int i = 0 ; i < n ; i++)
          {
              if(ar[i] < x)
              {
                  if(mk[x - ar[i]])
                  {
                     if(x - ar[i] == ar[i]){
                     if(freq[ar[i]] > 1){
                     sol += ((freq[ar[i]] * (freq[ar[i]] - 1)) / 2);
                     mk[ar[i]] = false;
                     }//mk[]
                     }
                     else
                     {
                        mk[ar[i]] = false;
                        mk[x - ar[i]] = false;
                        sol += (freq[ar[i]] * freq[x - ar[i]]);
                     }
                  }
              }
          }
          cout<<sol<<"\n";
    return 0;
}
