#include <bits/stdc++.h>

const int MAXN = 1000005;
using namespace std;
char text[MAXN] , c;

int main()
{
    //ios_base::sync_with_stdio(0);cin.tie(0);

    int t;
    scanf("%d" , &t);
    while(t--)
    {
        int n;
        scanf("%d" , &n); int sol = 0;
        for(int i = 0 ; i < n ; i++)
        {
            sol += 1<<i;
        }
        printf("%d\n" , sol);
    }
    return 0;
}
