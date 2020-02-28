#include <bits/stdc++.h>

using namespace std;
char c;

typedef pair <string , string> par;

vector <par> ans;
string ar[505];

void activate(int a , int b)
{
  int ta = ar[a].size();
  int tb = ar[b].size();
  if(ta >= tb) return;

     for(int i = 0 ; i + ta <= tb ; i++)
     {
       bool flag = true;int cont = 0;
       for(int j = i ; j - i < ta ; j++){

        if(ar[a][j - i] != ar[b][j])
        flag = false;

        cont++;
       }
       if(flag && cont)
       {
         ans.push_back(make_pair(ar[a] , ar[b]));
         return;
       }
     }
     return;
}
int main()
{
   //cout<<isupper('E');
   ios_base::sync_with_stdio(0);cin.tie(0);
   int n;
   cin>>n;
   for(int i = 0 ; i < n ; i++)
     cin>>ar[i];

     for(int i = 0 ; i < n ; i++)
        for(int j = 0 ; j < n ; j++)
        {
           if(i != j)
             activate(i , j);
        }

    sort(ans.begin() , ans.end());

    cout<<ans.size()<<"\n";
    for(int i = 0 ; i < ans.size() ; i++)
       cout<<ans[i].first<<" "<<ans[i].second<<"\n";
   return 0;
}
