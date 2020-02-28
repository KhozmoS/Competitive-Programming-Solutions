#include <bits/stdc++.h>

using namespace std;
char c;
string ar;

int main()
{
   //cout<<isupper('E');
   ios_base::sync_with_stdio(0);cin.tie(0);
   while(getline(cin , ar))
   {
     int cont = 0 , spa = 0;
     for(int i = 0 ; i < ar.size() ; i++)
     {
         if(ar[i] != ' ' && isupper(ar[i])) cont++;

         if(ar[i] == ' ') spa++;
     }
     if(spa != --cont)cout<<"awful\n";

     else cout<<"correct\n";
     //cout<<cont<<" "<<spa<<"\n";
   }



   return 0;
}
