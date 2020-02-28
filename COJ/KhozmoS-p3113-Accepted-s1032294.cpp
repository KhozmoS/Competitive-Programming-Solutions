#include <bits/stdc++.h>

using namespace std;
typedef pair <int , int> par;
const int MAXN = 100005;

par ar[MAXN];
int tot; int n; int prof = -1;
int dist(int x , int y , int x1 , int y1)
{
    return abs(x - x1) + abs(y - y1);
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    for(int i = 0 ; i < n ; i++)
    {
      cin>>ar[i].first>>ar[i].second;
      if(i)
      tot += (dist(ar[i].first , ar[i].second , ar[i - 1].first , ar[i - 1].second));
    }
    for(int i = 0 ; i < n ; i++)
    {
      //if(!i)
      //{
        ///if(dist(ar[i].first , ar[i].second , ar[i + 1].first , ar[i + 1].second) > prof)
       // prof = dist(ar[i].first , ar[i].second , ar[i + 1].first , ar[i + 1].second);
      //}
      if(i == n - 1){
        if(dist(ar[i].first , ar[i].second , ar[i - 1].first , ar[i - 1].second) > prof)
        prof = dist(ar[i].first , ar[i].second , ar[i - 1].first , ar[i - 1].second);
      }
      else
      {
          int comp = dist(ar[i].first , ar[i].second , ar[i + 1].first , ar[i + 1].second) + dist(ar[i].first , ar[i].second , ar[i - 1].first , ar[i - 1].second);
       //   cout<<comp<<"\n";
          comp -= dist(ar[i + 1].first , ar[i + 1].second , ar[i - 1].first , ar[i - 1].second);
          if(prof < comp)
          prof = comp;
      }
    }
    //cout<<tot<<"\n";

    cout<<tot - prof<<"\n";

    return 0;
}
