#include <bits/stdc++.h>

using namespace std;
const int MAXN = 500005;

vector <string> text;

char c ;
char cad[MAXN];
int ta , t , N;
int main()
{
     scanf("%[^\n]", cad);scanf("%c", &c);

       ta = strlen(cad);
       string pegar  = "";
       for(int i = 0 ; i < ta ; i++)
       {
           if(cad[i] == ' '){
               string ver = "";
                t = pegar.size();
            for(int k = 0 ; k < t ; k++)
            ver += tolower(pegar[k]);

           if(ver == "kroketten")
            pegar = "croqueta";

           text.push_back(pegar);
           pegar = "";
           continue;
           }
           else if(ta - i == 1)
           {
               pegar += cad[i];
               string ver = "";
                t = pegar.size();
            for(int k = 0 ; k < t ; k++)
            ver += tolower(pegar[k]);

           if(ver == "kroketten")
            pegar = "croqueta";

           text.push_back(pegar);
           pegar = "";
           continue;
           }

           pegar += cad[i];
       }

        N = text.size();
       for(int i = 0 ; i < N ; i++)
       cout<<text[i]<<" ";
    return 0;
}
