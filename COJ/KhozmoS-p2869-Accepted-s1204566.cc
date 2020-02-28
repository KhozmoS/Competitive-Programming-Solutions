#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAX = 1e5 + 5;

struct nod {
    int best, left, right, lo, hi;
    nod(int a = 0, int b = 0, int c = 0, int d = 0, int e = 0) : best(a), left(b), right(c), lo(d), hi(e) {}
} tree[4 * MAX];

int val[MAX], pos[MAX];

nod comb(nod a, nod b) {
    if(!a.lo)
        return b;
    if(!b.hi)
        return a;
    nod ret = nod(max(a.best, b.best), a.left, b.right, a.lo, b.hi);
    if(val[a.hi] < val[b.lo]) {
        assert(a.hi + 1 == b.lo);
        ret.best = max(ret.best, a.right + b.left);
        if(a.hi - a.lo + 1 == a.best) {
            ret.left += b.left;
        }
        if(b.hi - b.lo + 1 == b.best) {
            ret.right += a.right;
        }
        ret.best = max(ret.best, max(ret.right, ret.left));
    }
    return ret;
}

void build(int node, int left, int right) {
    if(left == right) {
        pos[left] = node;
        tree[node] = nod(1, 1, 1, left, left);
        return;
    }
    int middle = (left + right) / 2;
    build(2 * node, left, middle);
    build(2 * node + 1, middle + 1, right);
    tree[node] = comb(tree[2 * node], tree[2 * node + 1]);
}

nod query(int node, int left, int right, int lo, int hi) {
    if(lo > right || hi < left) {
        return nod();
    }
    if(lo <= left && right <= hi) {
        return tree[node];
    }
    int middle = (left + right) / 2;
    return comb(query(2 * node, left, middle, lo, hi),
                query(2 * node + 1, middle + 1, right, lo, hi));
}

void update(int node, int v) {
    val[node] = v;
    int p = pos[node] / 2;
    while(p != 0) {
        tree[p] = comb(tree[2 * p], tree[2 * p + 1]);
        p /= 2;
    }
}

char text[10];
int n, q, a, b;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    while(cin >> n >> q) {
        for(int i = 1; i <= n; i++)
            cin >> val[i];
        build(1, 1, n);

        while(q--) {
            cin >> text >> a >> b;
            if(text[0] == 'Q')
                cout << query(1, 1, n, a + 1, b + 1).best << "\n";
            else
                update(a + 1, b);
        }
    }
}