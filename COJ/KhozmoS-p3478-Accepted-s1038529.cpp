#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

char cad[1000005];
int main()
{
    scanf("%s", cad);
    int len = strlen(cad);
    int cant = 0;
    int val = 0;
    vector<int>aux;
    for(int i = len-1; i >= 0; i--)
    {
        val+=(cad[i]-48)*(1<<cant);
        cant++;
        if(cant==3)
        {
            aux.push_back(val);
            cant=0;
            val=0;
        }
    }
    if(cant>0)
    {
        aux.push_back(val);
    }
    reverse(aux.begin(),aux.end());
    for(int i = 0; i < (int)aux.size(); i++)
    {
        printf("%d",aux[i]);
    }
    printf("\n");

    return 0;
}
