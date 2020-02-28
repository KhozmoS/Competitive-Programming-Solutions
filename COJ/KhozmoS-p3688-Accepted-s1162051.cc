//KhozmoS

#include<bits/stdc++.h>


using namespace std;

#define PB push_back
#define f first
#define s second
#define db double

typedef long long ll;
typedef pair<int , int> II;
typedef vector <int> VI;
typedef vector <II> VII;

const int MAX = 1e5+5;
db a , b , d1 , d2 , x1 , x3;

db sqrt3 = 1.7320508075688772935274463415059;

VI adl[MAX];

int ar[MAX];

db sq(db x)
{return x*x;}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);

    int t;cin>>t;

    while(t--){

    cin>>d1>>d2;
    db d3 = d1+d2;
	a = sq(d1) + sq(d2) + sq(d3);
	a /= (sqrt3 * 2.00000);

	cout<<setprecision(8)<<fixed<<a<<"\n";
    }
}
