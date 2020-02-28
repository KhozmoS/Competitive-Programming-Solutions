#include <bits/stdc++.h>

using namespace std;


typedef  long long ll;
typedef vector <int> vi;
const int MAX = 1e5 + 5;

int RMQ[MAX][21] , ar[MAX] , H[MAX][2] , n;
vi ans;
stack <int> st;
void build()
{
    for(int i = 1 ; i <= n ; i++)
    {
        while(!st.empty())
        {
            int x = st.top();
            if(ar[x] < ar[i] || i==n)
            {
                H[x][0] = i;
                st.pop();
            }
            else break;
        }
        st.push(i);
    }
    st.pop();
    for(int i = n ; i >= 1 ; i--)
    {
        while(!st.empty())
        {
            int x = st.top();
            if(ar[x] < ar[i] || i==1)
            {
                H[x][1] = i;
                st.pop();
            }
            else break;
        }
        st.push(i);
    }
    st.pop();
}
int query(int a , int b)
{
    int l = (int)__lg(b - a + 1);
    return min(RMQ[a][l] , RMQ[b - (1<<l) + 1][l]);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n;
  for(int i = 1 ; i <= n ; i++)
     cin>>ar[i];

  int k = n-1;
  for(int i = 1 ; i <= k ; i++)
      RMQ[i][0] = min(ar[i] , ar[i+1]);

  for(int sz = 1 ; (1<<sz) <= k ; sz++)
        for(int i = 1 ; i + (1<<sz) <= k+1 ; i++)
            RMQ[i][sz] = min(RMQ[i][sz-1] , RMQ[i+(1<<(sz-1))][sz-1]);
  build();

  for(int i = 2; i < n ; i++)
  {
      if(ar[i] > ar[i-1] && ar[i] > ar[i+1])
      {
          int alt = ar[i];
          int j = -1;
          if(H[i][0] != n)
             j = H[i][0];

          if(j != -1)
              alt = ar[i] - query(i , j-1);

          if(alt < 150000) continue;

          j = -1;
          if(H[i][1] != 1)
             j = H[i][1];

          if(j != -1)
              alt = ar[i] - query(j , i-1);

          if(alt < 150000) continue;

          ans.push_back(i);
      }
  }
  for(int i = 0 ; i < ans.size() ; i++)
        cout<<ans[i]<<(i == (ans.size()-1) ? "\n" : " ");
}
