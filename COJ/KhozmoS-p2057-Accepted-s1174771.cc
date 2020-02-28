#include <bits/stdc++.h>

using namespace std;
int n;
string A[15];

bool check() {
    for(int i = 2; i <= n; i++)
        if(A[i] != "")
            return false;
    return true;
}

int main() {

    ios_base::sync_with_stdio(0);cin.tie(0);
    while(true){
        cin >> n;
        if(n == -1)break;

        for(int i = 0; i < n - 1; i++)
            cin >> A[i + 2];

        vector <int> sol;
        int cont = 0;

        while(!check()) {

            for(int i = 2; i <= n; i++) {
                if(A[i] == "")
                    continue;
                char c = A[i][0];
                if(c == '1') {
                    sol.push_back(i);
                    A[i] = A[i].substr(1);
                    break;
                } else {
                    int p = A[i][0] - '0';
                    char cc = A[p][0];
                    if((c - '0' == p) && (cc - '0' == i)) {
                        A[i] = A[i].substr(1);
                        A[p] = A[p].substr(1);
                        break;
                    }
                }
            }
            
        }
        for(int i = 0; i < sol.size(); i++)
            cout << sol[i];
        cout << "\n";
    }
}
