#include <bits/stdc++.h>

using namespace std;

typedef pair <int , int> ii;
typedef long long ll;
const ll mod = 1000000007;
const int MAX = 1e6+5;
int n,pos;
ll ar[MAX];
ll point[MAX];
int main()
{
   //ios_base::sync_with_stdio(0);cin.tie(0);
   cin>>n>>pos;
   for(int i= 1 ; i <= n ; i++) cin>>ar[i];
   for(int i= 1 ; i <= n ; i++) cin>>point[i];
   sort(point+1,point+1+n);
   ll nw = ar[pos]+ point[n];
   int cnt = pos;
   pos--;
   for(int i = pos ; i >= 1 ; i--)
   {
       //cout<<pos<<"\n";
       //system("pause");
       while(point[pos]+ar[i]>nw && pos)pos--;
       if(!pos)break;
       pos--;
       cnt--;
   }
   cout<<cnt<<"\n";
}
