#include <bits/stdc++.h>

using namespace std;
const int MAXN = 1000005;

int n , a , b;
int user[MAXN];
int m;
vector<int> sol;
bool mk[1005][1005];
int main()
{
   ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m;

     for(int i = 0 ; i < m ; i++)
     {
         cin>>a>>b;

         if(!mk[a][b]){
         user[a]++;
         mk[a][b] = true;
         }
     }
      int may = -1;
      for(int i = 1 ; i <= n ; i++)
       {
           if(user[i] > may)
           {
             sol.clear();
             sol.push_back(i);
             may = user[i];
           }
           else if(user[i] == may)
           {
               sol.push_back(i);
           }
       }
       sort(sol.begin() , sol.end());
       for(int i = 0 ; i < sol.size() ; i++)
       {
           cout<<sol[i]<<" ";
       }
        cout<<"\n";
   return 0;
}
