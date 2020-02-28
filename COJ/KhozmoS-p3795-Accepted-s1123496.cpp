#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second

const int MAX = 1e6 + 5;


int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);

	int t;
	cin>>t;
	while(t--)
	{
	   int n;
	   cin>>n;
	   int sum = 0;
	   for(int i = 1 ; i < n ; i++)
	   {
		  if(n % i == 0)
		    sum += i;
		     
		} 	
		
		if(sum < n) cout<<"deficient\n";
		
		else if(sum == n) cout<<"perfect\n";
		
		else cout<<"abundant\n";
		
	}
	
	
	
   ;;;;;  ;;;;  ;;;;;  ;
//	 ;    ;  ;  ;____  ; 
	 ;    ;  ;  ;      ;
   ;;;    ;;;;  ;;;;;  ;;;;;  
}

