
#include <bits/stdc++.h>

using namespace std;
const int MAX = 105;
int t , n , h[MAX] , w[MAX];


int main()
{
   ios_base::sync_with_stdio(0);cin.tie(0);	
    cin>>t;
    
    while(t--)
    {
	  cin>>n;
	  for(int i = 0 ; i < n ; i++)
	    cin>>h[i];
	  for(int i = 0 ; i < n ; i++)
	    cin>>w[i];
	  int ans = 0;  
	  for(int i = 0 ; i < n - 1 ; i++)
	  {
	    int dif = h[i] - w[i];
	    if(dif > 0)
	    {
		  ans += dif;
		  h[i + 1] += dif;
		}
		if(dif < 0)
		{
          ans -= dif;
          h[i + 1] += dif; 			
		}	  
	  }  
	  cout<<ans<<"\n";
    }	 
	
	 
	return 0;
}

