#include<bits/stdc++.h>

using namespace std;

int A[15];
int fact[15];

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0); 
    fact[0] = 1;
    for(int i = 1; i <= 8; i++)
        fact[i] = fact[i - 1] * i;

    int t;
    cin >> t;
    while(t--)
    {
        int N;
        cin >> N;
        for(int i = 0; i < N; i++)
            A[i] = i + 1;

        int cont = 0;
        bool flag = false;
        do
        {
            if(cont == fact[N] / 3)
            {
                for(int i = 0 ; i < N; i++)
                    if(i == N - 1)
                        cout << A[i] << endl;
                    else
                        cout << A[i];
                flag = true;
            }
            cont++;

        }while(next_permutation(A, A + N) && !flag);
    }

    return 0;
}

