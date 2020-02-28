#include <bits/stdc++.h>

using namespace std;

typedef pair <int, int> p;

#define x first
#define y second

char cad[1000];
char ans[1000];

double area(double a, double b, double c){
    double sp = (a + b + c) / 2;
    return sqrt(sp * (sp - a) * (sp - b) * (sp - c));
}

double dist(p a, p b){
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    return sqrt(dx * dx + dy * dy);
}

int main()
{
    int t;
    cin >> t;
    double sol = 0.0;
    while(t--){
        int ax, ay, bx, by, cx, cy;
        scanf("%s%d%d%d%d%d%d", cad, &ax, &ay, &bx, &by, &cx, &cy);

        double a = dist(p(ax, ay), p(bx, by));
        double b = dist(p(ax, ay), p(cx, cy));
        double c = dist(p(bx, by), p(cx, cy));

        double aaa = area(a, b, c);
        if(aaa > sol){
            sol = aaa;
            strcpy(ans, cad);
        }
    }
    printf("%s %.2lf km^2\n", ans, sol);
    //cout << ans << " " << sol << " km^2\n";
    return 0;
}
