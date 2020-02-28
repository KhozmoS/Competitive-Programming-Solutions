#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e5 + 5;

int ar[MAX] , freq[MAX * 10];

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t , n;
    cin>>t;
    while(t--)
    {
       cin>>n;
       
       for(int i = 0 ; i < n ; i++)
          cin>>ar[i];
          
      int a = 0;
      int b = 0;    
      int ans = 0;
      while(b < n)
      { 
		 if(freq[ar[b]]) 
		 {
	        while(ar[a] != ar[b]){ 
			  freq[ar[a]] = 0;	
	          a++;
		  }
	          //cout<<b<<"\n";
	          freq[a] = 0;
	          a++;   		 
		 }
		 ans = max(ans , b - a + 1);
		 freq[ar[b]]++; 
		 b++;
	  }
      cout<<ans<<"\n";    
      for(int i = 0 ; i < n ; i++) freq[ar[i]] = 0;
    }
    return 0;
}

