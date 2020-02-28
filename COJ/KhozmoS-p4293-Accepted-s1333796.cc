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
int L[MAX];
int R[MAX];
int infinity = mod;

	ll inv = 0;
	int A[MAX];
	void Merge(int p, int q, int r) {
		int n1 = q - p + 1;
		int n2 = r - q;

		// create arrays L[1 ... n1 + 1] and R[1 ... n2 + 1]
		for(int i = 1 ; i <= n1 ; i++ ) {
			L[i] = A[p + i - 1];
		}
		for(int j = 1; j <= n2 ; j++)
			R[j] = A[q + j];
		L[n1 + 1] = infinity;
		R[n2 + 1] = infinity;
		int i = 1;
		int j = 1;
		for(int k = p ; k <= r ; k++) {
            if (L[i] <= R[j]) {
                    A[k] = L[i];
                    i = i + 1;
            }
            else {
                    A[k] = R[j];
                    j = j + 1;
                    inv = inv + n1 - i + 1;
            }
		}
	}
	void MergeSort( int p, int r){
        if ( p < r ) {
			int q = floor((p + r) / 2);
			MergeSort(p , q);
			MergeSort( q + 1, r);
			Merge( p, q, r);
        }
	}
// B < D*2 | D < C*2 | C < B*2

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    while(cin>>n && n) {
        for(int i = 1 ; i <= n ; i++) cin>>A[i];
        MergeSort(1,n);
        cout<<inv<<"\n";
        inv = 0;
    }
}
