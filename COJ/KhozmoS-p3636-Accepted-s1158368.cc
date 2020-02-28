#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef pair <int, int> ii;

typedef tree < ii, null_type, less <ii>, rb_tree_tag, tree_order_statistics_node_update > RB;

const int MAX = 6e5 + 5;

RB ST[4 * MAX];
int n, m, a, b, c, d, lista[MAX], pos[4 * MAX];

void build(int node, int left, int right) {
    ST[node].clear();
    if(left == right) {
        pos[left] = node;
        lista[left] = -1;
        return;
    }
    int middle = (left + right) / 2;
    build(2 * node, left, middle);
    build(2 * node + 1, middle + 1, right);
}

int query(int node, int left, int right, int lo, int hi, int val) {
    if(lo > right || hi < left)
        return 0;
    if(lo <= left && right <= hi)
        return ST[node].order_of_key(ii(val, n + 1));
    int middle = (left + right) / 2;
    return query(2 * node, left, middle, lo, hi, val) + query(2 * node + 1, middle + 1, right, lo, hi, val);
}

void update(int pp, int val) {
    int ant = lista[pp];
    int node = pos[pp], tmp;
    while(node != 0) {
        if(ant != -1)
            ST[node].erase(ST[node].find(ii(ant, pp)));
        ST[node].insert(ii(val, pp));
        node >>= 1;
    }
    lista[pp] = val;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    while(cin >> n >> m) {
        build(1, 1, n);

        while(m--) {
            cin >> a >> b >> c;
            b++;
            if(a) {
                c++;
                cin >> d;
                cout << query(1, 1, n, b, c, d) << "\n";
            } else {
                update(b, c);
            }
        }
    }
}
