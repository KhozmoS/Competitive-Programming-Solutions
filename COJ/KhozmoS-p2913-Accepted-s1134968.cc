//============================================================================
// Name        : Jose Carlos Gonzalez Fernandez
// Author      : Kaga2
// Version     :
// Copyright   : UCI2ndTWF
// Description :
//============================================================================


#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string.h>

#include <vector>
#include <limits>
#include <queue>
#include <cstdlib>
#include <string>
#include <map>
#include <math.h>
#include <limits>
#include <bitset>
#include <set>
#include <time.h>
#include <stack>
#include <complex>
#include <list>
#include <math.h>
using namespace std;
#define ll long long
#define ld long double
#define ull unsigned long long
#define uint unsigned int
#define MP make_pair
#define PB push_back

#define FOR(i,n) for(int i=0;i<n;i++)
#define FAB(i,a,b) for(int i=a;i<b;i++)
#define FORR(i,n) for(int i=n;i>=0;i--)



int primos[] = {0,2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};

int d[200];
ll ans;
void work(int tot){
	ll x = 1;
	for (int i = 1; i <= tot; i ++){
		for (int j = 1; j < d[i]; j ++)
			if (primos[i] < double(ans) / x)
				x *= (ll) primos[i];
			else
				return ;
	}
	ans = min(x, ans);
}

#define MAXN 1000000
vector<int> divi[MAXN + 5];

void dfs(int x, int n, int limit){
	if (n == 1) {
		work(x - 1);
		return ;
	}
	for(int i=divi[n].size()-1;i>=0;i--){
		int p = divi[n][i];
		if (p <= limit){
			d[x] = divi[n][i];
			dfs(x + 1, n / p, p);
		}
	}
	/*
	for (int i = limit; i >= 2; i--)
		if (n % i == 0){
			d[x] = i;
			dfs(x + 1, n / i, i);
		}
	 */
}

vector<ll> lista;
void generate(){
	for(int i=2;i<=MAXN;i++)
		for(int j=1;i*j<=MAXN;j++)
			divi[i*j].push_back(i);

	ll oo = 1000000000000000000LL;
	int n;

	for(n=1;n<=103680;n++){
		ans = oo;
		if (n == 1)
			ans = 1;
		else
			dfs(1, n, n);
		if (ans != oo){
			//cout << n << " = " << ans << endl;
			lista.push_back(ans);
		}
	}


	ll last = lista[lista.size()-1];
	for(int i=lista.size()-2;i>=0;i--){
		if (lista[i] > last)
			lista[i] = -1;
		else
			last = lista[i];
	}
	int len = 0;
	cout << "{";
	for(int i=0;i<(int)lista.size();i++){
		if (lista[i] == -1) continue;
		if (i) cout << ",";
		len++;
		cout << lista[i];
		if (lista[i] > 1000000000LL)
			cout << "LL";
	}
	cout << "};" << endl;
	cout << len << endl;
}

ll salidas[156] = {1,2,4,6,12,24,36,48,60,120,180,240,360,720,840,1260,1680,2520,5040,7560,10080,15120,20160,25200,27720,45360,50400,55440,83160,110880,166320,221760,277200,332640,498960,554400,665280,720720,1081080,1441440,2162160,2882880,3603600,4324320,6486480,7207200,8648640,10810800,14414400,17297280,21621600,32432400,36756720,43243200,61261200,73513440,110270160,122522400,147026880,183783600,245044800,294053760,367567200,551350800,698377680,735134400,1102701600LL,1396755360LL,2095133040LL,2205403200LL,2327925600LL,2793510720LL,3491888400LL,4655851200LL,5587021440LL,6983776800LL,10475665200LL,13967553600LL,20951330400LL,27935107200LL,41902660800LL,48886437600LL,64250746560LL,73329656400LL,80313433200LL,97772875200LL,128501493120LL,146659312800LL,160626866400LL,240940299600LL,293318625600LL,321253732800LL,481880599200LL,642507465600LL,963761198400LL,1124388064800LL,1606268664000LL,1686582097200LL,1927522396800LL,2248776129600LL,3212537328000LL,3373164194400LL,4497552259200LL,6746328388800LL,8995104518400LL,9316358251200LL,13492656777600LL,18632716502400LL,26985313555200LL,27949074753600LL,32607253879200LL,46581791256000LL,48910880818800LL,55898149507200LL,65214507758400LL,93163582512000LL,97821761637600LL,130429015516800LL,195643523275200LL,260858031033600LL,288807105787200LL,391287046550400LL,577614211574400LL,782574093100800LL,866421317361600LL,1010824870255200LL,1444035528936000LL,1516237305382800LL,1732842634723200LL,2021649740510400LL,2888071057872000LL,3032474610765600LL,4043299481020800LL,6064949221531200LL,8086598962041600LL,10108248702552000LL,12129898443062400LL,18194847664593600LL,20216497405104000LL,24259796886124800LL,30324746107656000LL,36389695329187200LL,48519593772249600LL,60649492215312000LL,72779390658374400LL,74801040398884800LL,106858629141264000LL,112201560598327200LL,149602080797769600LL,224403121196654400LL,299204161595539200LL,374005201994424000LL,448806242393308800LL,673209363589963200LL,748010403988848000LL,897612484786617600LL};

int main(){
	cin.sync_with_stdio(0);

	//generate();

	int cas;
	ll n;
	cin >> cas;
	while(cas--){
		cin >> n;
		int p = upper_bound(salidas,salidas + 156, n) - salidas;
		cout << salidas[p-1] << "\n";
	}

	return 0;
}





