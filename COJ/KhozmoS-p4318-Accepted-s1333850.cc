#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pb push_back
#define db long double
#define NINF INT_MIN
typedef pair <int, int> ii;
typedef pair <ii, string> iis;
typedef vector <int> vi;
typedef long long ll;
const int MAX = 1e6+4;
//const  db sqrt2 = sqrt(2);

map <string , int> id;
int n;
iis dp[MAX];
vi v[MAX];
bool mk[MAX];
vector<int> grafo[MAX];
stack <int> top;
queue<int> cola;

int N, M, inDeg[MAX];

void dfs(int node)
{
	mk[node] = true;
	for(int i = 0 ; i < v[node].size() ; i++)
	{
		int x = v[node][i];
		if(mk[x]) continue;

		dfs(x);
	}
	top.push(node);
}


void solve( int s )
{
    dfs(s);
    while(!top.empty()) {

        int u = top.top();
        mk[u] = false;
        top.pop();
        for(int i = 0 ; i < v[u].size() ; i++) {
            int nw = v[u][i];
            dp[nw].f.f = max(dp[nw].f.f , dp[u].f.f+1);
        }

    }
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

void main2()
{
    ios_base::sync_with_stdio(0);cin.tie(0);

//    int t;cin>>t;

   while(cin>>n) {
        id.clear();
        int idx = 1;
    //    cin>>n;
        for(int i = 1 ; i <= n ; i++) {
            string a, b;
            cin>>a>>b;
            int idA , idB;
            if(id.find(a) == id.end()) {
                dp[idx].s = a;
                dp[idx].f.f = 1;
                idA = idx;
                id[a] = idx++;
            } else {
                idA = id[a];
            }
            if(id.find(b) == id.end()) {
                dp[idx].s = b;
                dp[idx].f.f = 1;
                idB = idx;
                id[b] = idx++;
            } else {
                idB = id[b];
            }
            v[idA].pb(idB);
//           cout<<idA<<" "<<idB<<" "<<dp[idA].s<<" "<<dp[idB].s<<"\n";
            dp[idB].f.s++;
        }
        for(int i = 1 ; i < idx ; i++) {
            if(!dp[i].f.s)
                solve(i);
        }
        sort(dp +1 , dp+idx);
        for(int i = 1 ; i < idx ; i++) {
            cout<<dp[i].f.f<<"."<<dp[i].f.s<<" "<<dp[i].s<<"\n";


            dp[i] = iis(ii(0,0) , "");
            v[i].clear();
        }
    }

}




int main()
{
	run_with_stack_size(main2, 100*1024*1024);
	return 0;
}







