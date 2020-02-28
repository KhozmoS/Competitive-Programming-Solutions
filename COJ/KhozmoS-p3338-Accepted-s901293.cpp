#include<bits/stdc++.h>

using namespace std;
char cod[100];char c;
char alph[27];int k;
int main ()
{
     int t;
    scanf("%d" , &t);
      while(t--){
    scanf(" %[^\n]",&cod);
    scanf(" %[^\n]",&alph);
     int ta = strlen(cod);
     for(int i = 0 ; i < ta ; i++)
     {
         if(cod[i] != ' ')
         {
             cod[i] = alph[cod[i] - 'A'];
         }
     }
     cout<<++k<<" "<<cod<<"\n";
      }
    return 0;
}
