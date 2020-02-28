#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e3 + 5;
int arr[MAX][MAX] , md[MAX] , mi[MAX] , n , m , H[MAX][MAX] , ans;
stack <int> pila;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    while(cin>>n>>m)
    {
        ans = 0;
        memset(arr, 0 , sizeof(arr));
        memset(H, 0 , sizeof(H));
        for(int i = 1 ; i <= n ; i++)
            for(int j = 1 ; j <= m ; j++)
            {
               cin>>arr[i][j];
               H[i][j]++;
               if(arr[i-1][j] && arr[i-1][j] + 1 == arr[i][j])
                    H[i][j] += H[i-1][j];
            }

        for(int i = 1 ; i <= n ; i++)
        {
          for(int j = 1 ; j <= m+1 ; j++){
            while(!pila.empty())
            {
                int x = pila.top();
                if(H[i][x] > H[i][j] || arr[i][x] != arr[i][j] - (j - x))
                {
                    md[x] = j-1;
                    pila.pop();
                }
                else break;
            }
            pila.push(j);
           }
            pila.pop();
          for(int j = m ; j >= 0 ; j--){
            while(!pila.empty())
            {
                int x = pila.top();
                if(H[i][x] > H[i][j] || arr[i][x] != arr[i][j] + (x - j))
                {
                    mi[x] = j+1;
                    pila.pop();
                }
                else break;
            }
            pila.push(j);
          }
            pila.pop();
          for(int j = 1 ; j <= m ; j++)
          {
              int cur = (H[i][j] * (md[j] - mi[j] + 1));
              ans = max(cur , ans);
          }
          memset(md , 0 , sizeof(md));
          memset(mi , 0 , sizeof(mi));
       }
       cout<<ans<<"\n";
    }
}
