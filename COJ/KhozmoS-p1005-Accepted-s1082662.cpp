#include <stdio.h>
#include <algorithm>

using namespace std;

struct vuelo
{
    int inicio;
    int final;
    int precio;
};

bool operator<(vuelo a, vuelo b)
{
    return a.inicio < b.inicio;
}

int dp[10005];
int inicios[10005];
vuelo vuelos[10005];

int siguiente(int indice, int n)
{
    int final = vuelos[indice].final;
    return lower_bound(inicios + indice, inicios + n, final) - inicios;
}

int main()
{
    int t, n;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
        {
            scanf("%d%d%d", &vuelos[i].inicio, &vuelos[i].final, &vuelos[i].precio);
            vuelos[i].final = vuelos[i].inicio + vuelos[i].final;
        }

        sort(vuelos, vuelos + n);
        for(int i = 0; i < n; i++)
            inicios[i] = vuelos[i].inicio;

        dp[n] = 0;
        for(int i = n - 1; i >= 0; i--)
            dp[i] = max(dp[i + 1], dp[siguiente(i, n)] + vuelos[i].precio);

        printf("%d\n", dp[0]);
    }
    return 0;
}

