#include <bits/stdc++.h>

using namespace std;

const int MAXN = 20005;

int N;
bool mk[MAXN];
char C[MAXN];
int wayf[MAXN];

string bfs()
{
    if(N == 1)
        return "1";

    string res = "";
    fill(mk, mk + N, false);
    queue <int> cola;

    cola.push(1);
    mk[1] = true;
    C[1] = '1';
    while(!cola.empty())
    {
        int num = cola.front();
        cola.pop();

        if(num == 0)
        {
            int ini = 1, fin = num;
            while(ini != fin)
            {
                res = C[fin] + res;
                fin = wayf[fin];
            }
            res = C[ini] + res;
            return res;
        }

        int n1 = (num * 10) % N;

        if(!mk[n1])
        {
            mk[n1] = true;
            cola.push(n1);
            C[n1] = '0';
            wayf[n1] = num;
        }
        int n2 = (num * 10 + 1) % N;
        if(!mk[n2])
        {
            mk[n2] = true;
            cola.push(n2);
            C[n2] = '1';
            wayf[n2] = num;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        cin >> N;
        cout << bfs() << endl;
    }

    return 0;
}
