#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        double x1, y1, x2, y2;
        scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);

        double sol = x1 * y2 - x2 * y1;
        printf("%.1lf\n", abs(sol / 2));
    }
    return 0;
}
