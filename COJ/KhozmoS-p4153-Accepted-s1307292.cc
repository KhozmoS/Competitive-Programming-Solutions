#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define sz(c) (c).size()

typedef long long ll;
typedef pair<int , int > ii;
typedef vector <int> vi;

const ll mod = 1e9+7;
const int MAX = 1e6+7;
int ar[MAX*5];

void f(int n , int in , int fn)
{
    if(in==fn) return;
    int mt = (in+fn)>>1;
    f(n/2,mt+1,fn);
    f(n/2,in,mt);
    mt = (fn-in+1)>>1;
    for(int i = in ; i <= mt+in-1 ; i++){
       // cout<<i<<" "<<in<<" "<<fn<<" "<<mt<<"\n";
        swap(ar[i],ar[mt+i]);
    }
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n , t;
    cin>>n>>t;
    n = pow(2,n);
    for(int i = 1 ; i <= n ; i++)
    {
        cin>>ar[i];
        if(t%2==0)
            cout<<ar[i]<<(i==n?"\n":" ");
    }
    if(t%2==0)
       return 0;

     for(int i = n ; i >= 1 ; i--)
    {
        cout<<ar[i]<<(i==1?"\n":" ");
    }
}
