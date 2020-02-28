#include <cstdio>

#define M 5000

int A[11][M+1];
int leading_zeros = 1;

void print_sol(int n,int k,int m)
{
    if (k == 0 && m == 1) return;
    if (k == 0 || A[k][m - 1] >= n)
    {
        if (!leading_zeros)
            printf ("0");
        print_sol(n,k,m-1);
    }
    else
    {
        leading_zeros = 0;
        printf ("1");
        print_sol(n - A[k][m - 1],k - 1,m - 1);
    }
}

int main()
{
    int N,K;

    scanf ("%d %d", &N, &K);

    if(K == 1)
    {
        printf ("1");
        for (int i = 0; i < N - 1; i++)
            printf ("0");
        printf ("\n");
        return 0;
    }

    A[0][1] = 1;
    for (int j = 1; j <= M; j++)
        for (int i = 0; i <= 10; i++)
        {
            if (i == 0)
                A[i][j] = 1;
            else
                A[i][j] = A[i - 1][j - 1] + A[i][j - 1];
            if(A[i][j] > 10000000)
                A[i][j] = 10000000;
        }

    print_sol(N,K,M);
    printf ("\n");

    return 0;
    }
