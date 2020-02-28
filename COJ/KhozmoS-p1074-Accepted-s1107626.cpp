#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e5 + 5;

int ans[13];
int cas;
int n;
int ar[13];
bool mk[13];
void solve(int pos)
{
    if(pos == n)
    {
        cout<<++cas<<" : ";
        for(int i = 0 ; i < n ; i++)
            cout<<ans[i]<<(i == (n - 1) ? "\n" : " ");

        return;
    }

    for(int i = 1 ; i <= n ; i++)
    {
        if(pos == 0){
          //if(i == 1)cout<<mk[i]<<"\n";
          mk[i] = true;
          ans[pos] = i;
          solve(pos + 1);
          mk[i] = false;
          }
        else
        {
          bool flag = true;
          for(int j = pos - 1 ; j >= 0 ; j--)
          {
              if(ans[j] == i + (pos - j) || ans[j] == i - (pos - j)){
                flag = false;
                break;
              }
          }
          if(flag && !mk[i])
          {
              mk[i] = true;
              ans[pos] = i;
              solve(pos + 1);
              mk[i] = false;
          }
        }
    }
}
int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0);

   while(cin>>n){
       solve(0);
       if(!cas) cout<<"No Solution.\n";
       cas = 0;
   }
    return 0;
}
