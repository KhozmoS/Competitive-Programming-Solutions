#include <bits/stdc++.h>
using namespace std;

#define MAX 35
#define ll long long

char S[MAX];
ll N;

int main() {

	cin >> S >> N;
	ll len = strlen(S);
	if(N <= len){
		cout << S[N-1] << '\n';
	}else{
		int k = 1;
		ll v = 2LL;
		for(; v*len < N; v*=2LL, k++);
		v *= len;
		for(int i = 1; i <= k; i++){
		  v /= 2LL;
		  if(N > v){
			 N -= v;
			 N--;
			 if(N==0) N = v;
		  }
		}
		cout << S[N-1] << '\n';
	}

	return 0;
} 