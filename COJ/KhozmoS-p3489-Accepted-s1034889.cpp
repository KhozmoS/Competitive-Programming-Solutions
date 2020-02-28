#include <bits/stdc++.h>

using namespace std;
const int mod = 1000000007;
typedef long long ll;
const int MAXN = 11111111;
int dp[MAXN];
int c[MAXN];
int ps[MAXN];

vector <int> p;
vector<int> ele;
int n , pr;


int main()
{
   ios_base::sync_with_stdio(0);cin.tie(0);

   dp[0] = 1;
   ele.push_back(0);

   cin>>n>>pr;

    for(int i = 0 ; i < n ; i++) cin>>c[i];

    for(int i = 0 ; i < n ; i++) cin>>ps[i];

    for(int i = 0 ; i < n ; i++)
    {
      int ta;int j = 0;
      do{

       int pos = ele[j];

       for(int k = 0 ; k < c[i] ; k++){
       if(pos + ps[i] >= MAXN) break;

       dp[pos + ps[i]]++;
       pos = pos + ps[i];
      // cout<<pos<<" ";
       p.push_back(pos);
       }
       //cout<<"\n";
       j++;
       ta = ele.size();

      }while(j < ta);

      for(int k = 0 ; k < p.size() ; k++)
      ele.push_back(p[k]);

      p.clear();
    }
    cout<<dp[pr]<<"\n";
    return 0;
}
