#include <bits/stdc++.h>

using namespace std;
const int MAXN = 1111;

vector <int> adl[MAXN];

bool A[MAXN];
bool B[MAXN];
bool mk[MAXN];

int n , m;

int main() {

 //ios_base::sync_with_stdio(0);cin.tie(0);

   cin>>n>>m;

   for(int i = 0 ; i < m ; i++)
   {
       int a , b; cin>>a>>b;

       adl[a].push_back(b);
       adl[b].push_back(a);
   }
   for(int i = 1 ; i <= n ; i++)
   {
       if(!mk[i])
       {
           A[i] = true;
           mk[i] = true;
           for(int k = 0 ; k < adl[i].size() ; k++)
           {
             mk[adl[i][k]] = true;
             B[adl[i][k]] = true;
           }
       }
   }
    bool flag = false;
   for(int i = 1 ; i <= n ; i++)
   {
       for(int k = 0 ; k < adl[i].size() ; k++)
       if(A[i] == A[adl[i][k]])
       flag = true;
   }
   if(flag) cout<<"NO\n";

   else cout<<"YES\n";
	return 0;

}
