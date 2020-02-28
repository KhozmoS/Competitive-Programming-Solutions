
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MAX = 1e5 + 5;
ll ar[MAX] , r;
int n , q;
int bin(int ini , int fin)
{
   if(fin - ini < 5)
   {
	  for(int i = ini ; i <= fin ; i++)
	    if(ar[i] >= r)
	     return i;
	  
	 return 0;       
   }
   int mit = (fin + ini) / 2;
   if(ar[mit] < r){
   ini = mit;
   return bin(mit , fin);
   }
   return bin(ini , mit);
}
int main()
{
   ios_base::sync_with_stdio(0);cin.tie(0);	
    cin>>n;
    
    for(int i = 1 ; i <= n ; i++) cin>>ar[i] , ar[i] += ar[i - 1];	 
	
	cin>>q;
	//cout<<ar[5]<<"\n";
	while(q--)
	{
	  cin>>r;
	  int ans = bin(1 , n);
	  if(ans)
	    cout<<ans<<"\n";
	  else
	    cout<<"none\n";    	
	}
	 
	return 0;
}

