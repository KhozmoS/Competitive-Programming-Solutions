#include <bits/stdc++.h>


using namespace std;
const int MAX = 1e5 + 5;
struct par {

  int a , b;
  par (int aa , int bb){
    a = aa;
    b = bb;
  }

  par(){a = 0; b = 0;}

  bool operator < (const par &X) const{
      return b < X.b;
  }

}A[MAX];

multiset <int , greater <int> > s;
int n , k;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n>>k;

    for(int i = 0 ; i < n ; i++) cin>>A[i].a>>A[i].b;
    sort(A , A + n);
    int ans = 0;
    for(int i = 0 ; i < n ; i++)
    {
        multiset <int> :: iterator it = s.lower_bound(A[i].a);
        if(it != s.end())
        {
            ans++;
            s.erase(it);
            s.insert(A[i].b);
        }
        else if(s.size() < k)
        {
            ans++;
            s.insert(A[i].b);
        }
    }

    cout<<ans<<"\n";

}
