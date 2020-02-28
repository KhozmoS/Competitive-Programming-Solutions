#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

#define MAX 205

bool can;
int n, m, a, b, c, to, color[MAX];

vector <int> v[MAX];
vector <int> :: iterator ite;

queue <int> q;

int main() {
    
    while(scanf("%d", &n) && n) {
        scanf("%d", &m);
        can = true;

        for(int i = 1; i <= m; i++) {
            scanf("%d %d", &a, &b);
            v[a].push_back(b);
            v[b].push_back(a);
        }
        memset(color, 0, sizeof(color));

        color[0] = 1;
        q.push(0);
        while(!q.empty()) {
            c = q.front();
            q.pop();

            for(ite = v[c].begin(); ite != v[c].end() && can; ite++) {
                to = *ite;
                if(color[to] && color[to] == color[c])
                    can = false;
                if(!color[to]) {
                    color[to] = 3 - color[c];
                    q.push(to);
                }
            }
        }


        for(int i = 0; i < n; i++)
            v[i].clear();

        if(can)
            printf("BICOLORABLE.\n");
        else
            printf("NOT BICOLORABLE.\n");
    }
}