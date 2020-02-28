//KhozmoS

#include<bits/stdc++.h>


using namespace std;

#define PB push_back
#define f first
#define s second

typedef long long ll;
typedef pair<int , int> II;
typedef vector <int> VI;
typedef vector <II> VII;

const int MAX = 1005;

int n, m , p[MAX] ;
VI adl[MAX] , white;
bool mk[MAX];


int main()
{
  ios_base::sync_with_stdio(0),cin.tie(0);
  string txt;

  while(cin>>txt)
  {
  	if(txt == "*") return 0;

    ll lcm = 1;

    for(ll i = 0 ; i < txt.size() ; i++)
    	if(txt[i] == 'Y')
    	  lcm = (lcm * (i+1)) / __gcd(lcm , i+1);
    bool ans = true;
    for(ll i = 0; i < txt.size() ; i++)
    	if(txt[i] == 'N' && !(lcm % (i+1)))
     	{
           ans = false;
     	}
    if(ans){cout<<lcm<<"\n";}
    else cout<<"-1\n";
  }
}
