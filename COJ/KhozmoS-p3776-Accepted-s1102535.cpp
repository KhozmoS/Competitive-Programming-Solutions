#include <bits/stdc++.h>

using namespace std;

const int MAXN = 55;

typedef long long ll;
ll TP[MAXN][MAXN];

string toStr(ll n){
    string sol = "";
    while(n > 0){
        sol = (char)((n % 10) + '0') + sol;
        n /= 10;
    }
    return sol;
}

int main()
{
    

    for(int i = 0; i < MAXN; i++)
        TP[i][0] = TP[i][i] = 1;

    for(int i = 1; i < MAXN; i++)
        for(int j = 1; j < i; j++)
            TP[i][j] = TP[i - 1][j] + TP[i - 1][j - 1];

    int n;
    while(cin >> n){
        if(n == 1){
            cout << "Tan(A)\n";
            continue;
        }

        if(n == 2){
            cout << "2Tan(A)/(1-Tan^2(A))\n";
            continue;
        }



        string num = "(" + toStr(TP[n][1]) + "Tan(A)";
        bool sign = true;
        for(int i = 3; i <= n; i += 2){
            if(!sign)
                num += "+";
            else
                num += "-";

            sign = !sign;
            if(TP[n][i] != 1)
                num += toStr(TP[n][i]);
            num += "Tan^" + toStr(i) + "(A)";
        }
        num += ")";

        string den = "(1";
        sign = true;
        for(int i = 2; i <= n; i += 2){
            if(!sign)
                den += "+";
            else
                den += "-";

            sign = !sign;
            if(TP[n][i] != 1)
                den += toStr(TP[n][i]);
            den += "Tan^" + toStr(i) + "(A)";
        }
        den += ")";
        string sol = num + "/" + den;

        cout << sol << "\n";
    }


    return 0;
}
