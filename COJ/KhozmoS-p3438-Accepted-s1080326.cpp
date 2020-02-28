#include <bits/stdc++.h>

using namespace std;

const int MAX = 10000005;
typedef pair <int , int > par;

short dp[MAX];
int n , a , b;
int low , hig;
vector <par> A;

int main()
{
  low = MAX;
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n;
  for(int i = 0 ; i < n ; i++)
  {
      cin>>a>>b;
      low = min(low , a);
      hig = max(hig , b);
      dp[a]++; dp[b + 1]--;
  }
   hig++;
   for(int i = low ; i <= hig ; i++)
    dp[i] += dp[i - 1];
   for(int i = 1000000 ; i < MAX ; i++)
   {
     if(dp[i])
      for(int j = i ; j < MAX ; j++)
        if(!dp[j])
        {
         A.push_back(make_pair(i , j - 1));
         i = j;
         break;
        }
   }
   cout<<A.size()<<"\n";

   for(int i = 0 ; i < A.size() ; i++)
    cout<<A[i].first<<" "<<A[i].second<<"\n";

  return 0;
}
