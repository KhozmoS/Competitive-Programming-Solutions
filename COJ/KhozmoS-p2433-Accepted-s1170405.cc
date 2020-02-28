#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second

const int MAX = 1e2 *5 + 5;
bool mk[30];string cad;
int arr[MAX][MAX] , n , m;
char M[MAX][MAX];
stack <int> pila;
int AC[MAX][MAX][30] , md[MAX] , mi[MAX];
bool ok(int x , int y , int xx , int yy)
{
    for(int k = 0 ; k < 26 ; k++)
        if(mk[k] && !(AC[xx][yy][k] - AC[xx][y-1][k] - AC[x-1][yy][k] + AC[x-1][y-1][k]))
            return false;
    return true;
}
int main()
{
   ios_base::sync_with_stdio(0);cin.tie(0);
   while(cin>>n>>m && n){
   memset(mk , false , sizeof(mk));
   memset(AC , false , sizeof(AC));
   memset(arr , false , sizeof(arr));
   cin>>cad;
   for(int i = 0 ; i < cad.size() ; i++)
        mk[cad[i]-'a'] = true;
   for(int i = 1 ; i <= n ; i++)
        for(int j = 1 ; j <= m ; j++)
        {
           cin>>M[i][j];
           if(mk[M[i][j] - 'a'])
           {
              arr[i][j]++;
              AC[i][j][M[i][j] - 'a']++;
           }
           if(arr[i][j])
                arr[i][j] += arr[i-1][j];
           for(int k = 0 ; k < 26 ; k++)
                AC[i][j][k] += (AC[i][j-1][k] + AC[i-1][j][k] - AC[i-1][j-1][k]);
        }
    int ans = 0;
    for(int i = 1 ; i <= n ; i++)
    {
        for(int j = 1 ; j <= m+1 ; j++)
        {
            while(!pila.empty())
            {
                int x = pila.top();
                if(arr[i][x] > arr[i][j])
                {
                    md[x] = j-1;
                    pila.pop();
                }
                else break;
            }
          if(arr[i][j])
               pila.push(j);
        }
        for(int j = m ; j >= 0 ; j--)
        {
            while(!pila.empty())
            {
                int x = pila.top();
                if(arr[i][x] > arr[i][j])
                {
                    mi[x] = j+1;
                    pila.pop();
                }
                else break;
            }
            if(arr[i][j])
                pila.push(j);
        }
        //blabla
        for(int j = 1 ; j <= m ; j++)
        {
            int cur = (arr[i][j] * (md[j] - mi[j] + 1));
            if(ok(i - arr[i][j] + 1 , mi[j] , i , md[j]))
                ans = max(cur , ans);
        }
        memset(md , 0 , sizeof(md));
        memset(mi , 0 , sizeof(mi));
    }
    cout<<ans<<"\n";
   }
}
