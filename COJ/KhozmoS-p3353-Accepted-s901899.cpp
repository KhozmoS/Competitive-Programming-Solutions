#include <bits/stdc++.h>

using namespace std;

vector<int>vc;
int n , m , men , sum , x;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    
    cin>>n>>m;
     for(int i = 0 ; i < n ; i++)
     {
         cin>>x;
         if(x < 0)
          vc.push_back(x);
     }
     sort(vc.begin() , vc.end());
     int ta = vc.size();
     for(int i = 0 ; i < m ; i++)
     {
         if(i == ta)
            break;
         sum += (vc[i] * -1);
     }
      cout<<sum<<"\n";
    return 0;
}
