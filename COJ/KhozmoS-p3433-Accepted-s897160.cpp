#include<bits/stdc++.h>
using namespace std;
 const int MAX = 105;
 bool T[MAX];
 bool X[MAX];
 bool Y[MAX];
 int ss, is ,x ,y ,k ,tot ,n;
int main()
{
  scanf("%d%d",&x,&y);
   for(int i = 0; i < x ; i++)
   {
       scanf("%d",&n);
       X[n] = true;
       T[n] = true;
   }
   for(int i = 0; i < y ; i++)
   {
       scanf("%d",&n);
       Y[n] = true;
       T[n] = true;
   }
   for(int i = 1; i < MAX ;i++)
   {
       if(X[i] == true && Y[i] == true){
          ss++;
          tot++;
       }
       else if(T[i] == true)
       {
          tot++;
       }
   }
     int ws = tot - ss;
     is = 100 - tot;
     cout<<"Unsolvable: "<<is<<"\n";
     cout<<"Weakly solvable: "<<ws<<"\n";
     cout<<"Strongly solvable: "<<ss<<"\n";

return 0;
}
