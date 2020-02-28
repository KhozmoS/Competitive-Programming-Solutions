#include <bits/stdc++.h>

using namespace std;

struct tri {
    int a, b, c;
} lista[8][3];

int orden[] = { 1, 2, 3, 4, 5, 6 };

bool valid(int a, int b, int c, int d, int e, int f) {
    int pos[] = { a, b, c, d, e, f, };
    for(int i = 0; i < 5; i++)
        if(lista[orden[i]][pos[i]].b != lista[orden[i + 1]][pos[i + 1]].a)
            return false;
    if(lista[orden[5]][f].b != lista[orden[0]][a].a)
        return false;
    return true;
}

int a, b, c, sol;
char s[2];

int main() {
    while(1) {
        for(int i = 1; i <= 6; i++) {
            cin >> a >> b >> c;
            lista[i][0] = (tri) { a, b, c };
            lista[i][1] = (tri) { b, c, a };
            lista[i][2] = (tri) { c, a, b };
        }

        sol = 0;
        do {
            for(int tri1 = 0; tri1 < 3; tri1++)
                for(int tri2 = 0; tri2 < 3; tri2++)
                    for(int tri3 = 0; tri3 < 3; tri3++)
                        for(int tri4 = 0; tri4 < 3; tri4++)
                            for(int tri5 = 0; tri5 < 3; tri5++)
                                for(int tri6 = 0; tri6 < 3; tri6++)
                                    if(valid(tri1, tri2, tri3, tri4, tri5, tri6))
                                        sol = max(sol, lista[orden[0]][tri1].c + lista[orden[1]][tri2].c
                                                     + lista[orden[2]][tri3].c + lista[orden[3]][tri4].c
                                                     + lista[orden[4]][tri5].c + lista[orden[5]][tri6].c);
        }
        while(next_permutation(orden, orden + 6));

        if(sol)cout << sol << '\n';
        else cout << "none\n";

        cin >> s;
        if(s[0] == '$')break;
    }
}