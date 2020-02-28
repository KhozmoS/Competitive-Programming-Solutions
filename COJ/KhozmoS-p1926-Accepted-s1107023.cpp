#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAX = 1005;
const ll mod = 1e9 + 7;

int id, dp[MAX][2], mult[MAX][2];

vector <int> lista[MAX];
map <string, int> code;
string root, a, b;

void dfs(int node) {
    int si = 0, no = 0;
    for(int i = 0; i < lista[node].size(); i++) {
        int to = lista[node][i];
        dfs(to);
        mult[node][0] |= (dp[to][0] == dp[to][1]);
        mult[node][1] |= mult[to][0];
        si += dp[to][0];
        no += max(dp[to][1], dp[to][0]);
    }
    dp[node][0] = no;
    dp[node][1] = 1 + si;
}

int main() {
//    freopen("a.in", "r", stdin);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;

    while(cin >> n && n) {
//    cin >> n;
        code.clear();
        cin >> root;
        code[root] = ++id;
        for(int i = 1; i < n; i++) {
            cin >> a >> b;
            int &aa = code[a];
            int &bb = code[b];
            if(!aa)aa = ++id;
            if(!bb)bb = ++id;
            lista[bb].push_back(aa);
        }
        dfs(1);
        if(dp[1][0] == dp[1][1]) {
            cout << dp[1][0] << " No\n";
        }
        else if(dp[1][0] > dp[1][1]) {
            cout << dp[1][0] << " ";
            if(!mult[1][0])
                cout << "Yes\n";
            else
                cout << "No\n";
        }
        else {
            cout << dp[1][1] << " ";
            if(!mult[1][1])
                cout << "Yes\n";
            else
                cout << "No\n";
        }
        for(int i = 1; i <= id; i++)
            lista[i].clear();
        id = 0;
        memset(dp, 0, sizeof(dp));
        memset(mult, 0, sizeof(mult));
    }
}