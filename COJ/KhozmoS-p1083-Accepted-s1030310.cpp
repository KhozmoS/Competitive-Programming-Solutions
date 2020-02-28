#include <bits/stdc++.h>

using namespace std;
const int MAXN = 1000005;

string sol;

int k , l , m;
int n;
bool est[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);

    cin>>k>>l>>m;

    for(int i = 1 ; i < MAXN ; i++)
    {
      bool flag = false;
      if(i - k >= 0)
      {
        if(!est[i - k])
            flag = true;
      }
      if(i - l >= 0)
      {
        if(!est[i - l])
            flag = true;
      }
      if(i - 1 >= 0)
      {
        if(!est[i - 1])
            flag = true;
      }
      est[i] = flag;
    }
    for(int i = 0 ; i < m ; i++)
    {
        cin>>n;
        if(est[n])
        sol += 'A';
        else
        sol += 'B';
    }
    cout<<sol<<"\n";
    return 0;
}
