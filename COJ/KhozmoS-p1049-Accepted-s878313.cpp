#include <bits/stdc++.h>

using namespace std;
  int n,suma;
int main()
{
    scanf("%d",&n);
      if(n < 0){
    for(int i = n; i < 0;i++)
      suma += i;
      suma++;
      }
      else
    for(int i = n; i > 0;i--)
      suma += i;
    cout<<suma<<endl;
    return 0;
}
