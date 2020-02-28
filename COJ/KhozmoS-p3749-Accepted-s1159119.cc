#include<bits/stdc++.h>


using namespace std;


#define PB push_back
const int MAX = 20000+5;
const int mx[] = {-1 , 0 , 1 , 0};
const int my[] = {0 , 1 , 0 , -1};

vector <int> adl[MAX];
int M[25][1005] , p[MAX] , id[25][1005] , n , m;
bool mk[MAX];

bool kunh(int node)
{
    if(mk[node]) return false;

    mk[node] = true;

    for(int i = 0 ; i < adl[node].size() ; i++)
    {
        int x = adl[node][i];

        if(!p[x]){p[x] = node; return true;}


        if(kunh(p[x]))
        {
            p[x] = node;

            return true;
        }
    }
    return false;
}

int main()
{
   ios_base::sync_with_stdio(0);cin.tie(0);
   int cas = 1;
   while(cin>>n>>m && n)
   {
       memset(M , 0 , sizeof(M));
       memset(p , 0 , sizeof(p));
       memset(id , 0 , sizeof(id));
       int on = 0;
       for(int i = 1 ; i <= n ; i++)
          for(int j = 1 ; j <= m ; j++)
          {
             char c;
             cin>>c;
             if(c == '.'){ M[i][j]++;on++;}

          }
      // cout<<on<<"\n";
       int nod = 1;
       vector <int> B;
       for(int i = 1 ;i <= n ; i++)
          for(int j = 1 ; j <= m ; j++)
          {
              if(M[i][j] && ((i%2) == (j%2)))
              {
                 //cout<<i<<" "<<j<<"\n";
                 id[i][j] = nod;
                 B.PB(nod++);
                 for(int k = 0 ; k < 4 ; k++)
                 {
                     int x = mx[k] + i;
                     int y = my[k] + j;
                     if(M[x][y]){
                       if(id[x][y])
                           adl[id[i][j]].PB(id[x][y]);
                       else{
                           id[x][y] = nod++;
                           adl[id[i][j]].PB(id[x][y]);
                       }
                     }
                 }
              }
          }
       /*for(int i = 1 ; i <= nod ; i++){cout<<i<<": ";
             for(int j = 0 ; j < adl[i].size() ; j++)
                cout<<adl[i][j]<<" ";

                cout<<"\n";
             }*/
       int ans = 0;
       for(int i = 0 ; i < B.size() ; i++)
       {
           ans += kunh(B[i]);
           memset(mk , false ,sizeof(mk));
       }
       B.clear();
       cout<<"Case #"<<cas++<<": "<<(on - (ans*2))/2 + (on - (ans*2)) % 2<<"\n";
       for(int i = 0 ; i < MAX ; i++)
          adl[i].clear();
   }

}
