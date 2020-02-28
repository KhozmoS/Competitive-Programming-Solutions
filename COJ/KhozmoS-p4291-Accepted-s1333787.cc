#include <bits/stdc++.h>

using namespace std;


#define f first
#define s second
#define pb push_back
#define db double
#define sz(c) (c).size()
#define all(c) (c).begin(),(c).end()

typedef long long ll;
typedef pair <int , int > ii;
typedef pair <ii , int > iii;
typedef vector <int> vi;
typedef vector <ii> vii;
typedef vector <vi> vvi;
typedef vector <vii> vvii;

const ll mod = 1e9+5;
const int MAX = 1e6+5;


// B < D*2 | D < C*2 | C < B*2

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    string A,B; int a,b;
    while( cin>>A>>a && cin>>B>>b ) {
        if( A[0] == B[0] ) {
            if(a==b) {
                cout<<"Draw\n";
            } else {
                cout<<(a>b?"Tobby\n":"Naebbirac\n");
            }
        } else if( A[0] == 'B' && B[0] == 'D') {
            cout<<(a*2>b?"Tobby\n":"Naebbirac\n");
        } else if( A[0] == 'D' && B[0] == 'B') {
            cout<<(a<b*2?"Naebbirac\n":"Tobby\n");
        } else if( A[0] == 'D' && B[0] == 'C') {
            cout<<(a*2>b?"Tobby\n":"Naebbirac\n");
        } else if( A[0] == 'C' && B[0] == 'D') {
            cout<<(a<b*2?"Naebbirac\n":"Tobby\n");
        } else if( A[0] == 'C' && B[0] == 'B') {
            cout<<(a*2>b?"Tobby\n":"Naebbirac\n");
        } else if( A[0] == 'B' && B[0] == 'C') {
            cout<<(a<b*2?"Naebbirac\n":"Tobby\n");
        }

    }


}
