#include <bits/stdc++.h>

using namespace std;
char cad[101];
int ta;
int main()
{
    cin>>cad;
    ta = strlen(cad);
     if(ta % 2 == 0){
      reverse(cad + 0 ,cad + (ta / 2));
      reverse(cad + ta/2 ,cad + ta);
     }
     else
     {
         reverse(cad + 0 , cad + (ta / 2));
         reverse(cad + ((ta / 2) + 1),cad + ta);
     }
     cout<<cad<<"\n";
    return 0;
}
