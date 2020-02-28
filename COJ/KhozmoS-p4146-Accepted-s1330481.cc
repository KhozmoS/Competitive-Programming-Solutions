#include <bits/stdc++.h>
using namespace std;

const int MAX = 2e5 + 5;
int n, dp[MAX], h[MAX], ans = 0;
vector <int> g[MAX];

void dfs(int u, int p = -1) {
	int best = 0, a = 0, b = 0;
	
	for(int v : g[u]) {
		if(v != p) {
			dfs(v, u);
			
			int o = max(h[v], dp[v]);
			best = max(best, o);
			
			if(o > a) {
				b = a;
				a = o;
			}
			
			else if(o > b)
				b = o;
			
			h[u]++;
		}
	}
	
	if(h[u] == 0)
		return;
		
	dp[u] = h[u] - 1 + best;
	
	ans = max(ans, h[u] - 1 + (u != 1) + best);
	
	if(h[u] >= 2)
		ans = max(ans, h[u] - 2 + (u != 1) + a + b);
}


static void run_with_stack_size(void (*func)(), size_t stsize)
{
	char * stack, *send;
	stack = (char*) malloc(stsize);
	send = stack + stsize - 16;
	send = (char*) ((uintptr_t)send / 16 * 16);
	asm volatile(
		"mov %%rsp, (%0)\n"
		"mov %0, %%rsp\n"
		:
		: "r" (send));
	func();
	asm volatile(
		"mov (%0), %%rsp\n"
		:
		: "r" (send));
	free(stack);
}


void main2() {
	scanf("%d", &n);
	
	for(int i = 1; i < n; i++) {
		int a, b; scanf("%d%d", &a, &b);
		g[a].push_back(b);
		g[b].push_back(a);
	}
	
	dfs(1);
	
	printf("%d\n", ans);
}

int main()
{
	run_with_stack_size(main2, 100*1024*1024);
	return 0;
}
