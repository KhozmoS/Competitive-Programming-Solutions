#include <bits/stdc++.h>

using namespace std;

int n , s;
bool mk[105];
int cost[105];
vector <int> v[105];
int ans = 0;
int mx = 0;
void bfs()
{
    cost[s] = 0;
    queue <int> q;
    q.push(s);
    mk[s] = true;

    while(!q.empty())
    {
        int node = q.front();q.pop();

        for(int i = 0 ; i < v[node].size() ; i++)
        {
            int nw = v[node][i];
            if(cost[node]+1 > cost[nw])
            {
                cost[nw] = cost[node] + 1;
                mx = max(cost[nw] , mx);
                q.push(nw);
                mk[nw] = true;
            }
        }
    }
    for(int i = 0 ; i < 105 ; i++)
        if(cost[i] == mx)
            {
                ans = i;
                return;
            }
}

  string oct (long long n)
  {
      string a = "";
      while(true){
         a = char(n % 8 + 48) + a;
         n /= 8;
         if(n < 1)
          break;
      }
      return a;
  }
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);

  //for(int i = 1; i <= 10 ; i++)
   // cout<<(pow(2 , i)-1) * (pow(2 , i)+1)<<" "<<oct((pow(2 , i)-1) * (pow(2 , i)+1))<<"\n";
    int n;cin>>n;
  if(n%3==1)
  {
      string ans = "3";
      for(int i = 0 ; i < (n/3)*2; i++)
        ans += "7";
        cout<<ans<<"\n";
  }
  if(n%3==2)
  {
      string ans = "17";
      for(int i = 0 ; i < (n/3)*2; i++)
        ans += "7";
      cout<<ans<<"\n";
  }
  if(n%3==0)
  {
     string ans = "";
     for(int i = 0 ; i < (n/3)*2 ; i++)
        ans += "7";
        cout<<ans<<"\n";
  }
}
