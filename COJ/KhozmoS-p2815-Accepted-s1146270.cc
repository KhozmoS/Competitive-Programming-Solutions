#include <bits/stdc++.h>

using namespace std;

#define cik(i, a, b, c) for(int i =(a); i <=(b); i +=(c))

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int T; cin >> T;

    cik(i, 1, T, 1){
        string A, B; cin >> A >> B;

        int Sol = 0;
        for(int i = 0; i < A.size();){
            if(i + B.size() <= A.size()){
                if(A.substr(i, B.size()) == B){
                    A = A.substr(0, i) + A.substr(i + B.size());
                    Sol++;
                    i = 0;
                }
                else {
                    i++;
                }
            }
            else{
                i++;
            }
        }

        cout << Sol << "\n";
    }

    return 0;
}
