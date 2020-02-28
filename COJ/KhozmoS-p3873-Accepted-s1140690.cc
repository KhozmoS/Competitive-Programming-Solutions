#include <bits/stdc++.h>


using namespace std;

const int MAX = (1e3 + 5) * 3;

char ans[MAX][MAX];

void ws(int x)
{
    int c = 0;
    for(int i = 1 ; c < x ; i += 2){
        c++;
        ans[10][i] = '.';
    }
}
void bs(int x)
{
    int c = 1;
    for(int i = 1 ; i <= 2110 ; i++)
        ans[2][i] = '.';
    for(int i = 2 ; c < x ; i += 2)
    {
        ans[1][i] = '.';
        c++;
    }
}
int main()
{
  for(int i = 0 ; i < MAX ; i++)
    memset(ans[i] , '@' , sizeof(ans[i]));
    int b , w;

    cin>>b>>w;
    bool flag = false;
    if(b - 1){
       bs(b-1);
       flag = true;
    }


    ws(w - flag);

    cout<<20<<" "<<2110<<"\n";
    for(int i = 1 ; i <= 20 ; i++){
      for(int j = 1 ; j <= 2110 ; j++)
           cout<<ans[i][j];

           cout<<"\n";
    }

}
