#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int MAXN = 2007;

int N, C;
bool mk[MAXN];
vector <int> adlist[MAXN];

bool bfs(int a, int b){

    fill(mk, mk + MAXN, false);
    queue <int> cola;
    cola.push(a);
    mk[a] = true;

    while(!cola.empty()){
        int nodo = cola.front();
        cola.pop();

        if(nodo == b)
            return true;

        for(int i = 0; i < adlist[nodo].size(); i++){
            int nn = adlist[nodo][i];
            if(mk[nn])continue;

            cola.push(nn);
            mk[nn] = true;
        }
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    while(cin >> N >> C){
        if(N == 0 && C == 0)break;

        int a, b, c;
        for(int i = 0; i < C; i++){
            cin >> a >> b >> c;
            adlist[a].push_back(b);
            if(c == 2)
                adlist[b].push_back(a);
        }
        cin >> a >> b;
        if(bfs(a, b) && bfs(b, a))
            cout << "1\n";
        else
            cout << "0\n";

        for(int i = 0; i <= N; i++)
            adlist[i].clear();

    }

    return 0;
}
