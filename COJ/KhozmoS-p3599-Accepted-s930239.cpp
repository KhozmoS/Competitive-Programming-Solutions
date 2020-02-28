#include <bits/stdc++.h>

using namespace std;
const int MAXN = 3011;
//int lad[4];
string cad;
int N , ta;
int va[MAXN][MAXN];
  bool check(int a ,int b)
  {
      int sum;
      bool flag = false;
      int X = b - a;
      int in = a;
      b -= a;
      a = a - a;

      for(int i = 0 ; i <= b ; i++)
      {
          int val = X - i;
          if(val >= a && val <= b)
          {
            //int sum = cad[val] + cad[i];
            if(!flag)
            {
                 sum = cad[val + in] + cad[i + in];
                flag = true;
            }
            else if(flag && (sum != cad[val + in] + cad[i + in]))
            {
                va[a + in][b + in] = 2;
                return false;
            }
          }
      }
        va[a + in][b + in] = 1;
        return true;
  }

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>cad;
   // ta = cad.size();
    cin>>N;
    while(N)
    {
        int a , b;
        cin>>a>>b;
        if(a > b)
        swap(a , b);
        if(va[a][b] == 0)
        {
            bool ok = check(a , b);
            if(ok)cout<<"yes\n";
            else cout<<"no\n";
        }
        else
        {
            if(va[a][b] == 1) cout<<"yes\n";
            else cout<<"no\n";
        }
        N--;
    }

    return 0;
}
