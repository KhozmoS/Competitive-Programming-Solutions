#include <bits/stdc++.h>

using namespace std;

#define cik(i, a, b, c) for(int i = (a); i <=(b); i +=(c))

const int maxn = 1e6 + 5;

int A[maxn];

int main()
{
    int N, G;
   cin >> N >> G;

        cik(i, 1, N, 1){
            int a, b; cin >> a >> b;

            A[i] = a - b;
        }

        int Sol = 0;

        sort(A + 1, A + N + 1);
        reverse(A + 1, A + N + 1);

        cik(i, 1, N, 1){
            if(A[i] > 0){
                Sol += 3;
            }
            else if(A[i] == 0){
                if(G){
                    G--;
                    Sol += 3;
                }
                else{
                    Sol ++;
                }
            }
            else{
                if(A[i] + G > 0){
                    Sol += 3;
                    G += A[i];
                    G--;
                }
                else if(A[i] + G == 0){
                    Sol++;
                    G += A[i];
                }
            }
        }

        cout << Sol << "\n";
}
