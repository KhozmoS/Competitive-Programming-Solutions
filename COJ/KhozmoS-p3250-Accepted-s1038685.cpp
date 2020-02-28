#include <bits/stdc++.h>

using namespace std;

int n, S[107], A[107];

int main(){

    int t;
    cin >> t;
    while(t--)
    {
	   cin >> n;
       fill (S, S + n + 1, 0);
       for (int i = 1; i <= n; i++){
            cin >> A[i];
            S[i] = S[i-1];
            for (int j = i - 1; j >= 1; j--){
                 if (S[i] < S[j-1] + (A[i] - A[j]))
                     S[i] = S[j-1] + (A[i] - A[j]);
            }
       }

       cout << S[n] << "\n";
    }
    return 0;
}
