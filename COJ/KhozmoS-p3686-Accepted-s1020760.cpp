#include<bits/stdc++.h>


using namespace std;
int M[1000005][20], A[1000005], N, Q, a, b, k , r;
void process2() {
        int i, j;
        for (i = 0; i < N; i++)
                M[i][0] = i;
        for (j = 1; 1 << j <= N; j++)
                for (i = 0; i + (1 << j) - 1 < N; i++)
                        if (A[M[i][j - 1]] > A[M[i + (1 << (j - 1))][j - 1]])
                                M[i][j] = M[i][j - 1];
                        else
                                M[i][j] = M[i + (1 << (j - 1))][j - 1];
}
int RMQ() {
        a--; b--;
        k = (int) log2(b - a + 1);
        if (A[M[a][k]] >= A[M[b - (1 << k) + 1][k]])
                return A[M[a][k]];
        else
                return A[M[b - (1 << k) + 1][k]];
}
int main() {

 ios_base::sync_with_stdio(0);cin.tie(0);
       int casos;
       cin>>casos;

       while(casos--){
       cin>>N>>r;
        for (int i = 0; i < N; i++)
                cin>>A[i];

        process2();

        for (int i = 0; i + r - 1 < N ; i++) {
                a = i + 1; b = i + r;
                cout<<RMQ()<<" ";
        }
        cout<<"\n";
       }
        return 0;
}
