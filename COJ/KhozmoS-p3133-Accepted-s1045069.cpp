#include <bits/stdc++.h>

using namespace std;


map <string , int> mapa;
const int MAXN = 300005;
string ar[MAXN];

long long freq[MAXN];
queue <string> cola;


int n , k;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n>>k;
    string x;
    long long sol = 0;
    int c = 0;
    for(int i = 0 ; i < n ; i++)
    {
      cin>>x;
      cola.push(x);

      if(i < k)
      sol += freq[x.size()];
      else{
      sol += freq[x.size()];
      }
      if(c == k)
      {
       freq[cola.front().size()]--;
       cola.pop();
       c--;
      }
        freq[x.size()]++;
        c++;
    }

    cout<<sol<<"\n";
    return 0;
}
