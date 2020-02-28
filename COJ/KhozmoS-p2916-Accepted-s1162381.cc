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


int main()
{

  ios_base::sync_with_stdio(0),cin.tie(0);

  int a ,b;
  while(cin>>a>>b)
        cout<<((__gcd(a , b)-1) ? "NO\n" : "YES\n");



}
