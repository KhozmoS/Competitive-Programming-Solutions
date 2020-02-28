//by pter

#include <cstdio>
#include <iostream>

using namespace std;

const int MAXN = 101;

int main()
{
    char a[MAXN][MAXN];
    
    int n,m;
    scanf("%d%d",&n,&m);
    int slashC = 0,area = 0;

    for(int i = 0; i < n; i++)
         for(int j = 0; j < m; j++)
              cin >> a[i][j];
              
    for(int i = 0; i < n; i++)
         for(int j = 0; j < m; j++)
         {
              if(a[i][j] != '.')
                   slashC++;
              else if(slashC & 1)
                   area++;
         }
          
    area += slashC / 2;
    printf("%d\n",area);  
    
    return 0;
}
