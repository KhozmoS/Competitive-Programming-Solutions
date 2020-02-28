#include <bits/stdc++.h>

using namespace std;

const int SIZE = 1e5 + 1,TB = 318;
int A[SIZE],lazy[TB];
vector<int> B[TB];

void update(int pos,int value){
    for(int i = 0;i < B[pos / TB].size();i++){
        if(B[pos / TB][i] == A[pos]){
            B[pos / TB][i] = A[pos] = value;
            break;
        }
    }

    sort(B[pos / TB].begin(),B[pos / TB].end());
}

int query(int i,int j,int x){

    int sol = 0;

    int Bi = i / TB;

    for(;i / TB == Bi && i < j;i++)
        if(A[i] <= x)
            sol++;

    int Bj = j / TB;

    for(Bi = i / TB;Bi != Bj;Bi++){
        sol += upper_bound(B[Bi].begin(),B[Bi].end(),x) - B[Bi].begin();
    }

    for(i = max(Bj * TB,i);i <= j;i++)
        if(A[i] <= x)
            sol++;

    return sol;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

//    freopen(".in","r",stdin);

    int N,Q;
    cin >> N >> Q;

    for(int i = 0;i < N;i++){
        cin >> A[i];
        B[i / TB].push_back(A[i]);
    }

    for(int i = 0;i < TB;i++)
        sort(B[i].begin(),B[i].end());

    while(Q--){
        char tp;
        cin >> tp;
        int i;

        if(tp == 'C'){
            int x;
            cin >> i >> x;
            i--;
            update(i,x);
        }
        else{
            int j,x;
            cin >> i >> j >> x;
            i--; j--;
            cout << query(i,j,x) << '\n';
        }
    }

    return 0;
}
