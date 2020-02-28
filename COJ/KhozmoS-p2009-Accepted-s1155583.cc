#include <bits/stdc++.h>
using namespace std;

const int MAXN = (1 << 20) + 5;

typedef pair <int, int> pii;
typedef vector<pii> vp;
typedef vector<int> vi;
typedef vector<bool> vb;

int N, sol;
vb mk(MAXN);
vi Sl, Sr;

vp maskbit(const vector<int> &K){
    vp mask;

    int sz = K.size();

    for (int msk = 0 ; msk < (1 << sz) ; msk++){
        for (int j = msk ; ; j = ((--j) & msk)){
            int s = 0;
            for (int bit = 0; bit < sz ; bit++){
                if (j & (1 << bit))
                    s = s - K[bit];
                else if (msk & (1 << bit))
                    s = s + K[bit];
            }
            if (s >= 0)
                mask.push_back(pii(s, msk));
            if(j == 0) break;
        }
    }

    sort(mask.begin(), mask.end());
    mask.resize(unique(mask.begin(), mask.end()) - mask.begin());

    return mask;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++){
        int v; cin >> v;
        if (i & 1)
            Sl.push_back(v);
        else
            Sr.push_back(v);
    }

    vp l = maskbit(Sl);
    vp r = maskbit(Sr);

    int lS = l.size();
    int rS = r.size();

    for (int p = 0, q = 0 ; p < lS && q < rS ; ){
        if (l[p].first < r[q].first)
            p++;

        else if (l[p].first > r[q].first)
            q++;

        else{
            int p2 = p;
            int q2 = q;

            for ( ; p2 < lS && l[p2].first == l[p].first ; p2++){}

            for ( ; q2 < rS && r[q2].first == r[q].first ; q2++){}

            for (int ii = p; ii < p2; ii++)
                for (int jj = q; jj < q2; jj++){
                    int ind = l[ii].second | (r[jj].second << Sl.size());
                    mk[ind] = true;
                }

            p = p2;
            q = q2;
        }
    }

    for(int i = 1 ; i < (1 << N) ; i++)
        sol += mk[i];

    cout << sol << "\n";
}
