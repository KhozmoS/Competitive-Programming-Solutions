#include <bits/stdc++.h>

using namespace std;

typedef pair <double, double> coo;
typedef pair <int, coo> par;

par A[10];
int B[10], ini, fin;
map <int, coo> P;

double dist(coo a, coo b)
{
    double dx = a.first - b.first;
    double dy = a.second - b.second;
    return sqrt(dx * dx + dy * dy);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    //cout << dist(coo(1, 1), coo(3, 1)) << endl;

    int N;
    cin >> N;

    for(int i = 0; i < N; i++)
    {
        int a;
        double x, y;
        cin >> a >> x >> y;
        A[i] = par(a, coo(x, y));
        P[a] = coo(x, y);
    }
    cin >> ini >> fin;
    for(int i = 0; i < N; i++)
        B[i] = A[i].first;

    sort(B, B + N);
    double sol = (1 << 30);
    do{
        if(B[0] == ini && B[N - 1] == fin)
        {
            //cout << "posible\n";
            double d = dist(P[B[0]], P[B[1]]);
            for(int i = 1; i < N - 2; i++)
                d += dist(P[B[i]], P[B[i + 1]]);
            d += dist(P[B[N - 2]], P[B[N - 1]]);

            sol = min(d, sol);
        }
    }while(next_permutation(B, B + N));
    printf("%.2lf\n", sol);

    return 0;
}
