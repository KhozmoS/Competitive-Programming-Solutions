#include <bits/stdc++.h>

using namespace std;

const int MAXN = 10005;
const int mod = 1000000007;

/*string mask = "000000";
string ver = "011011";

int sol;

void F(string cad, int ant)
{
    sol++;

    if(cad == ver)
        return;

    for(int i = 1 ; i <= 5 ; i++)
    {
        if(i == 3)
            continue;

       if((ant == 1 && i == 3 || ant == 3 && i == 1) && cad[2] == '0')
            continue;
       if((ant == 1 && i == 9 || ant == 9 && i == 1) && cad[5] == '0')
            continue;
       if((ant == 1 && i == 7 || ant == 7 && i == 1) && cad[4] == '0')
            continue;
       if((ant == 2 && i == 8 || ant == 8 && i == 2) && cad[5] == '0')
            continue;
       if((ant == 3 && i == 7 || ant == 7 && i == 3) && cad[5] == '0')
            continue;
       if((ant == 3 && i == 9 || ant == 9 && i == 3) && cad[6] == '0')
            continue;
       if((ant == 7 && i == 9 || ant == 9 && i == 7) && cad[8] == '0')
            continue;
       if((ant == 4 && i == 6 || ant == 6 && i == 4) && cad[5] == '0')
            continue;
       if(cad[i] == '1')
        continue;

       string copia = cad;
       copia[i] = '1';
       F(copia , i);
    }
}*/
int main()
{
   ios_base::sync_with_stdio(0);cin.tie(0);

    int f , c;

 int cas = 1;
    while(cin>>f>>c)
    {
        if(!f && !c)
            break;
        if(f > c)
            swap(f , c);

        if(f == 1 && c == 1)
            cout<<"Case #"<<cas++<<": "<<"1\n";
        if(f == 1 && c == 2)
            cout<<"Case #"<<cas++<<": "<<"4\n";
        if(f == 1 && c == 3)
            cout<<"Case #"<<cas++<<": "<<"11\n";
        if(f == 2 && c == 2)
            cout<<"Case #"<<cas++<<": "<<"64\n";
        if(f == 2 && c == 3)
            cout<<"Case #"<<cas++<<": "<<"1392\n";
        if(f == 3 && c == 3)
            cout<<"Case #"<<cas++<<": "<<"389497\n";
    }
    return 0;
}
