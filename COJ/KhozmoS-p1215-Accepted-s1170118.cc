#include <bits/stdc++.h>

using namespace std;
const int MAX = 1005;
string cad;
int hora[10];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
    cin>>t;
    for(int cas = 1 ; t-- ; cas++){
        cin>>cad;
        reverse(cad.begin() , cad.end());

        int idx = 0;
        int pot = 1;
        int closes = 0;
        int num = 0;
        while(closes < 4)
        {
            if(cad[idx] == ')' && cad[idx + 1] == '*')
                num += pot;
            if(cad[idx] == '(')
            {
                pot *= 2;
                closes++;
            }
            idx++;
        }
        closes = 0;
        hora[6] = num;
        pot = 1;
        num = 0;
        while(closes < 3)
        {
            if(cad[idx] == ')' && cad[idx + 1] == '*')
                num += pot;
            if(cad[idx] == '(')
            {
                pot *= 2;
                closes++;
            }
            idx++;
        }
        hora[5] = num;
        pot = 1;closes = 0;
        num = 0;
        while(closes < 4)
        {
            if(cad[idx] == ')' && cad[idx + 1] == '*')
                num += pot;
            if(cad[idx] == '(')
            {
                pot *= 2;
                closes++;
            }
            idx++;
        }
        hora[4] = num;
        pot = 1;closes = 0;
        num = 0;
        while(closes < 3)
        {
            if(cad[idx] == '(')
            {
                pot *= 2;
                closes++;
            }
            else if (cad[idx] == ')' && cad[idx + 1] == '*')
                num += pot;
            idx++;
        }
        hora[3] = num;
        pot = 1;closes = 0;
        num = 0;
        while(closes < 4)
        {
            if(cad[idx] == '(')
            {
                pot *= 2;
                closes++;
            }
            else if (cad[idx] == ')' && cad[idx + 1] == '*')
                num += pot;
            idx++;
        }
        hora[2] = num;
         pot = 1;closes = 0;
        num = 0;
        while(closes < 2)
        {
            if(cad[idx] == '(')
            {
                pot *= 2;
                closes++;
            }
            else if (cad[idx] == ')' && cad[idx + 1] == '*')
                num += pot;
            idx++;
        }
        hora[1] = num;
        cout<<"Case "<<cas<<": "<<hora[1]<<hora[2]<<":"<<hora[3]<<hora[4]<<":"<<hora[5]<<hora[6]<<"\n";
    }

}
