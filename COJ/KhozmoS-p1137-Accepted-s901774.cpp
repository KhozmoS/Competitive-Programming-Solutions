#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100000;

int nodos, aristas;
int grado[MAXN];
bool mk[MAXN];
vector <int> N;
vector <int> adlist[MAXN];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int a, b, raiz;
    int k = 0;
    while(true)
    {
        while(cin >> a >> b, a && b)
        {
            if(a < 0 && b < 0)
                goto FIN;

            adlist[a].push_back(b);
            grado[b]++;
            aristas++;
            if(!mk[a]){
                mk[a] = true;
                N.push_back(a);
            }
            if(!mk[b]){
                mk[b] = true;
                N.push_back(b);
            }
            for(int i = 0; i < N.size(); i++)
                if( grado[ N[i] ] == 0)
                {
                    raiz = N[i];
                    break;
                }

        }
        if(N.size() == 0){
            cout<< "Case " << ++k << " is a tree.\n";
            continue;
        }

        bool flag = false;
        for(int i = 0; i < N.size(); i++)
            if(N[i] != raiz && grado[ N[i] ] != 1){
                flag = true;
                break;
            }

        if(N.size() - 1 == aristas && !flag)
            cout<< "Case " << ++k << " is a tree.\n";
        else
            cout<< "Case " << ++k << " is not a tree.\n";

        //limpieza
        for(int i = 0; i < N.size(); i++){
            adlist[N[i]].clear();
            mk[N[i]] = false;
            grado[N[i]] = 0;
        }
        aristas = 0;
        N.clear();
    }

    FIN:

    return 0;
}