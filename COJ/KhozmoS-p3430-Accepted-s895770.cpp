#include<bits/stdc++.h>
using namespace std;
char cad[100000];
char sol[100000];
stack<int>pila;
int main ()
{
    scanf(" %[^\n]",cad);
    int ta = strlen(cad);
     for(int i = 0 ; i < ta ; i++)
     {
         if(cad[i] == '(')
           pila.push(i);
         else if(cad[i] == ')'){
           reverse(cad + pila.top() + 1, cad + i);
           pila.pop();
         }
     }
     int p = 0;
        for(int i = 0 ; i < ta ; i++)
        {
            if(cad[i] != '(' && cad[i] != ')'){
                sol[p] = cad[i], p++;
            }
        }
        cout<<sol<<"\n";
    return 0;
}
