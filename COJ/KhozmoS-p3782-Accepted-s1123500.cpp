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
      bool flag = false;		
      int ant;
      for(int i = 0 ; i < 5 ; i++){
	  int x;
	  cin>>x;
	  if(i && x != ant + 1)
	     flag = true;
	    
	  ant = x;
      } 
	 if(flag) cout<<"N\n";
	 else cout<<"Y\n"; 	
    }
	
	
	
	
	
   ;;;;;  ;;;;  ;;;;;  ;
//	 ;    ;  ;  ;____  ; 
	 ;    ;  ;  ;      ;
   ;;;    ;;;;  ;;;;;  ;;;;;  
}

