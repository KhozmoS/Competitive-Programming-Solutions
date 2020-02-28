#include <bits/stdc++.h>
#define MAXN 35
using namespace std;
string cad;
int may[MAXN];
int men[MAXN];
int ta, mark;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>cad;
    ta = cad.size();
    //int m = 0;
    for(int i = 0 ; i < ta ; i++)
    {
        mark = i + 1;
        while(mark < ta)
        {
           if(cad[i] - 'a' > -33 && cad[i] - 'a' < -6)
           {
              int valc = cad[i] - 'A';
              if(cad[mark] - 'a' >= 0 && cad[mark] - 'a' < 26)
              {
                may[valc]++;
                mark++;
                continue;
              }
              if(cad[mark] - 'a' > -33 && cad[i] - 'a' < -6)
              {
                 if(valc >= cad[mark] - 'A')
                 {
                   may[valc]++;
                   mark++;
                   continue;
                 }
                 else
                 {
                    i = mark;
                    mark++;
                    continue;
                 }
              }
           }
            else if(cad[i] - 'a' >= 0 && cad[i] - 'a' <= 25)
            {
                int valc = cad[i] - 'a';
                if(cad[mark] - 'a' > -33 && cad[mark] - 'a' < -6)
                {
                    i = mark; mark++;
                    continue;
                }
                else if(valc < cad[i] - 'a')
                {
                   i = mark; mark++;
                   continue;
                }
                else if(valc >= cad[i] - 'a')
                {
                    men[valc]++;
                    mark++;
                    continue;
                }
            }
        }
        break;
    }
        int ma = -1; bool flag = false; int ask = 0;
        for(int i = 0 ; i < MAXN ; i++)
        {
            if(may[i] > ma)
            {
                ma = may[i];
                ask = i;
            }
        }
        for(int i = 0 ; i < MAXN ; i++)
        {
            if(men[i] > ma)
            {
                ma = men[i];
                ask = i;
                flag = true;
            }
        }
         if(!flag)
         {
            cout<<char('A' + ask)<<"\n";
         }
         else
            cout<<char('a' + ask)<<"\n";

    return 0;
}
