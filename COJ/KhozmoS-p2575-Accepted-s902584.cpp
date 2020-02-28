#include <vector>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long ll;
#define N 505

int P[N], rank[N];
int E[N], NOD[N];
bool vis[N];

void crear(int x){
	P[x] = x;
	rank[x] = E[x] = NOD[x] = vis[x] = 0;
}
int bus(int x){
	if(x != P[x])
		P[x] = bus(P[x]);
	return P[x];
}
void unir(int a, int b){
	int mx = bus(a);
	int my = bus(b);
	if(mx == my){
		E[mx]++;
		return;
	}
	if(rank[mx] > rank[my]){
		P[my] = mx;
		E[mx]++;
		NOD[mx]++;
	}
	else{
		P[mx] = my;
		E[my]++;
		NOD[my]++;
	}
	if(rank[mx] == rank[my])
		rank[my]++;
}

int n, m, a, b, cas;

int main(){
	while(scanf("%d%d",&n,&m), n || m){
		for(int i = 1; i <= n; ++i){
			crear(i);
		}
		for(int i = 1; i <= m; ++i){
			scanf("%d%d",&a, &b);
			unir(a,b);
		}

		int sol = 0;
		for(int i = 1; i <= n; ++i){
			a = bus(i);
			if(!vis[a]){
				vis[a] = 1;
				NOD[a]++;
				if(NOD[a] == E[a]+1){
					sol++;
				}
			}
		}
		printf("Case %d: ",++cas);
		if(!sol)
			printf("No trees.\n");
		else if(sol == 1)
			printf("There is one tree.\n");
		else
			printf("A forest of %d trees.\n",sol);
	}
	return 0;
}