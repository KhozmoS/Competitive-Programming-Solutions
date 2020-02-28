#include <bits/stdc++.h>

using namespace std;
const int MAX = 1e4+5;


const int NUM = 6;
const double inf = 1e9;

int a , l , h , vol , ans , n;
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>a>>l>>h;
	cin>>n;
	for(int i = 1 ; i <= n ; i++)
    {
        int x , y , z;
        cin>>x>>y>>z;
        if(x <= a && y <= l && z <= h && (x*y*z) > vol)
        {
            ans = i;
            vol = x*y*z;
        }
    }
    cout<<ans<<"\n";
}
