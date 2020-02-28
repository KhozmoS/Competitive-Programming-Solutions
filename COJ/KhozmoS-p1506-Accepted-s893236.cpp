#include<bits/stdc++.h>

using namespace std;
  string test ,rev ;
  float nota;
  int n ,m;
int main ()
{
    cin>>n;
    cin>>test;
    cin>>m;
      for(int i = 0 ;i < m ;i++)
      {
          cin>>rev;
          for(int j = 0 ;j < n ;j++)
          {
              if(rev[j] == '#')
                continue;
              else if(rev[j] == test[j])
                nota++;
              else
                nota = nota - 0.25;
          }
             printf("%.2f\n",nota);
             nota = 0;
      }
    return 0;
}
