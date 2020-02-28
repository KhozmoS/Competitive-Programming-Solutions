#include<bits/stdc++.h>
//4147

using namespace::std;

const int SIZE = 201;
long long DP[SIZE][SIZE][SIZE]; // [cant_dig][suma][modulo]
const long long MAX = 1e18 + 1;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int s,m,q;
	cin >> s >> m >> q;

	vector<int> pot10(SIZE);
	pot10[0] = 1 % m;
	for(int i = 1;i < SIZE;i++)
		pot10[i] = pot10[i - 1] * 10 % m;

	DP[0][0][0] = 1;
	for(int i = 1;i < SIZE;i++){
		for(int j = 0;j <= s;j++){
			for(int k = 0;k <= m;k++){
				for(int d = 0;d < 10;d++){
					if(d > j)
						continue;
					int sum_mod = d * pot10[i - 1] % m;
					DP[i][j][k] += DP[i - 1][j - d][(k - sum_mod + m) % m];
					DP[i][j][k] = min(DP[i][j][k],MAX);
				}
			}
		}
	}

	while(q--){
		long long query;
		cin >> query;

		int ss = s,mm = m;
		
		string sol = "";
		for(int l = 200;l >= 1;l--){
			bool flag = false;
			for(int d = 0;d < 10;d++){
				if(d > ss)
					break;
				ss -= d;
				int sum_mod = d * pot10[l - 1] % m;
				mm = (mm - sum_mod + m) % m;

				if(DP[l - 1][ss][mm] >= query){
					flag = true;
					sol += '0' + d;
					break;	
				}
				else{
					query -= DP[l - 1][ss][mm];
				}

				ss += d;
				mm = (mm + sum_mod) % m;
			}
			if(!flag){
				sol = "";
				break;
			}
		}

		if(sol == ""){
			cout << "NIE\n";	
		}
		else{
			int cont = 0;
			while(sol[cont] == '0' && cont < sol.size()) cont++;

			cout << sol.substr(cont,sol.size() - cont) << '\n';
		}
	}

	return 0;
}