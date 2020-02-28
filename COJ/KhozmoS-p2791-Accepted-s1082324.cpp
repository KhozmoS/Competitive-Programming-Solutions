#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;

const ll MAX = 1e5 + 5;

ll n, q, k, X1, X2, Y1, Y2, A, X;
ll tree[4 * MAX], prop[4 * MAX], tam[4 * MAX];

void build(ll node, ll left, ll right) {
    if(left == right) {
        cin >> tree[node];
        tam[node] = 1ll;
        return;
    }
    ll middle = (left + right) / 2;
    build(2 * node, left, middle);
    build(2 * node + 1, middle + 1, right);
    tam[node] = tam[2 * node] + tam[2 * node + 1];
    tree[node] = tree[2 * node] + tree[2 * node + 1];
}

void lazy(ll node, ll val) {
    tree[node] += val * tam[node];
    prop[node] += val;
}

ll query(ll node, ll left, ll right, ll lo, ll hi, ll x) {
    if(lo > right || hi < left)
        return 0;
    if(lo <= left && right <= hi) {
        ll val = tree[node];
        lazy(node, x);
        return val;
    }
    if(prop[node]) {
        lazy(2 * node, prop[node]);
        lazy(2 * node + 1, prop[node]);
        prop[node] = 0;
    }
    ll middle = (left + right) / 2;
    ll a = query(2 * node, left, middle, lo, hi, x);
    ll b = query(2 * node + 1, middle + 1, right, lo, hi, x);
    tree[node] = tree[2 * node] + tree[2 * node + 1];
    return a + b;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> q >> k;

    build(1, 1, n);

    while(q--) {
        cin >> X1 >> Y1 >> X2 >> Y2;
        if(X1 > Y1)swap(X1, Y1);
        if(X2 > Y2)swap(X2, Y2);
        ll a = query(1, 1, n, X1, Y1, k);
        ll b = query(1, 1, n, X2, Y2, k);
        if(a > b)A++;
        else if(a < b)X++;
    }
    cout << "Alfred: " << A << "\n";
    cout << "Xavier: " << X << "\n";
}