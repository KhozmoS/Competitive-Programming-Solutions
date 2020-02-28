#include <bits/stdc++.h>

using namespace std;
 string cad;
 int porgusto;
 const int MAXX = 11005;
 const int MAXN = 105;
 typedef pair <int , int > par;
 typedef pair <par , par > ver;
  par up , lef , down , rigt;
  par ini; par fin;
  int N , M;
  char camp[MAXN][MAXN];
 bool mk[MAXX][MAXX];
 bool rec[MAXN][MAXN];
 int to_num(par x)
 {
     int n = x.first * 100;
     n += x.second;
     return n;
 }
 bool check (par x , par y)
 {
     int i = to_num(x);
     int j = to_num(y);
     //if(i == 10000)
    // cout<<i<<' '<<j<<"\n";
     if(!mk[i][j])
     {
         mk[i][j] = true;
         return true;
     }
     return false;
 }
 bool vale (int x , int y)
 {
     if(x > 0 && x <= N && y > 0 && y <= M && camp[x][y] == '.')
     {
     rec[x][y] = true;
     return true;
     }
     return false;
 }
 int vec;
 int o = 1;
 int rompe;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    up.first = -1; up.second = 0;
    lef.first = 0; lef.second = -1;
    down.first = 1; down.second = 0;
    rigt.first = 0; down.second = 1;
    int mx [] = { -1 , 0 , 1 , 0};
    int my [] = { 0 , -1 , 0 , 1};

    cin>>N>>M;
     int u , v;
     cin>>u>>v;
     ini.first = u; ini.second = v;
     int p , q;
     cin>>p>>q;
     fin.first = p; fin.second = q;
     for(int i = 1 ; i <= N ; i++)
     for(int j = 1 ; j <= M ; j++)
     cin>>camp[i][j];
     //simulation
     int m = 0;int c = 0;par ant , act;
     act.first = 0; act.second = 0;
     int sol = 0;bool flag = false;
    // cout<<mov[0].first<<" "<<mov[0].second<<"\n";
     //int m = 0;
     while(to_num(ini) != to_num(fin))
     {
         if(m == 4)
         m = 0;
         int x = mx[m] + ini.first;
         int y = my[m] + ini.second;
        // if(vale(x , y))
        // cout<<vale(x , y)<<"\n";
        /*if(vale(x , y))
        {
           // cout<<m<<"\n";
            //cout<<o++<<"\n";
        }*/
         if(vale(x , y))
         {
             rompe = 0;
             ini.first = x;
             ini.second = y;
             sol++;
             /*for(int i = 1 ; i <= N ; i++){
             for(int j = 1 ; j <= M ; j++)
             cout<<rec[i][j]<<" ";
             cout<<"\n";
             }*/
             //cout<<sol<<'\n';
         }
         else{
             rompe++;
          sol++;
          //cout<<m<<'\n';
          m ++;
          goto DALE;
         }
         ant = act;
         act.first = x; act.second = y;
         if(!check(ant , act))
         {
             flag = true;
             break;
         }
        DALE:
        porgusto++;
        if(rompe == 4)
        {
            flag = true;
            break;
        }
     }
     if(flag)
     cout<<"impossible\n";
     else cout<<sol<<"\n";
    return 0;
}
