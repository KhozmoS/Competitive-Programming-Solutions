#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pb push_back
#define db double
#define sz(c) (c).size()
#define all(c) (c).begin(),(c).end()

typedef long long ll;
typedef pair <int , int> ii;
typedef pair <ii , int> iii;
typedef vector <int> vi;
typedef vector < vi > vvi;
typedef vector < ii > vii;
typedef vector < vii > vvii;

const int mod = 1e9+7;
const int MAX = 1e6+5;
const db SQRT3 = sqrt(3);
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    db h , k;
    cout<<setprecision(3)<<fixed;
    cin>>h>>k;
    db a = h*SQRT3;
    db b = h/SQRT3;
    db x = (a+k-b);
    cout<<x/2*SQRT3<<"\n";
}
