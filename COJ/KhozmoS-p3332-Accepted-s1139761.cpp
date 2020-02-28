#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll  N, M, SQRT;
int ta , t;

int main() {

    ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>t;
	while (t--) {
		cin>>N>>M;

		if (M % N != 0) {
			cout<<"0\n";
			continue;
		}
		if (M == N) {
			cout<<"1\n";
			continue;
		}
		M /= N;
		SQRT = sqrt(M)+1;
		ta = 0;
		for (int i = 2; i <= SQRT; i++) {
			if (M % i == 0) {
				ta++;
				while (M % i == 0)
					M /= i;
			}
		}
		if (M != 1)
			ta++;
		cout<<(int)pow(2, ta-1)<<"\n";
	}
	return 0;
}
