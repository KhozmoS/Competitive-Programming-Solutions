#include<bits/stdc++.h>


using namespace std;

#define PB push_back
#define f first
#define s second

typedef long long ll;
typedef pair<int , int> II;
typedef vector <int> VI;
typedef vector <II> VII;

const int MAX = 1e5+5;
int a , b;
VI adl[MAX];
VI v;

int ar[MAX];

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>a>>b;
    v.PB(a);
    v.PB(b);
    v[0]+=v[1];
	cout<<v[0]<<"\n";
}
