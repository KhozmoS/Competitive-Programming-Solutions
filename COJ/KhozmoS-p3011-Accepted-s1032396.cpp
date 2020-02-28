//by KhozmoS
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1127;

int sol[MAXN][20];
bool comp[MAXN];
vector <int> P;

void criba()
{
    for(int i = 4; i < MAXN; i += 2)
        comp[i] = true;

    for(int i = 3; i * i < MAXN; i += 2)
        if(!comp[i])
            for(int j = i * i; j < MAXN; j += 2 * i)
                comp[j] = true;

    P.push_back(2);
    for(int i = 3; i < MAXN; i += 2)
        if(!comp[i])
            P.push_back(i);

}


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    criba();

    sol[0][0] = 1;

    for(int i = 0; i < P.size(); i++)
      for(int j = 1120; j >= P[i]; j--)
        for(int k = 1; k <= 14; k++)
            if(sol[j - P[i]][k - 1])
              sol[j][k] += sol[j - P[i]][k - 1];

  int a, b;
    while(cin>>a>>b && (a || b))
    {
        cout << sol[a][b] << "\n";
    }

    return 0;
}
