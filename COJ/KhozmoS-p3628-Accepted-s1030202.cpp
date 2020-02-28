#include <bits/stdc++.h>

using namespace std;

char car;
string S;

int main(){

    //freopen("in","r",stdin);
    //freopen("a.out","w",stdout);

    while (scanf ("%c", &car) != EOF){

           string A = "", B = "";

           while (car != '\n'){
                  if (car != ' ' && car != '\n')
                      S += car;
                  scanf ("%c", &car);
                   if ((car == ' ' || car == '\n') && S != ""){
                      A += S[0];
                      //cout << S << endl;
                      S = "";
                  }
           }

           car = 'a';
           while (car != '\n'){
                  scanf ("%c", &car);
                  if ((car == ' ' || car == '\n')&&S!=""){
                      B += S[0];
                      //cout << S << endl;
                      S = "";
                  }
                  else
                    if (car != '\n'&& car != ' ')
                     S += car;
           }
           if(A == B)printf("yes\n");
           else printf("no\n");
    }

    return 0;
}
