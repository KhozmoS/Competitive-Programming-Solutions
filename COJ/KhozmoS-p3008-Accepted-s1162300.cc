        #include <bits/stdc++.h>

        using namespace std;

        typedef long long ll;

        char M[4][4];
        int id[4][4];
        int node;
        bool mk[1 << 10];
        int cost[1<<10];
        void bfs()
        {
            queue <int> cola;
            cola.push(node);
            mk[node] = true;
            cost[node] = 0;
            while(!cola.empty())
            {
                node = cola.front();
                cola.pop();
                if(!node) return;

                for(int i = 0 ; i < 3 ; i++)
                   for(int j = 0 ; j < 3 ; j++)
                    {
                       int x = (node ^ (1<<id[i][j]));
                       if(i)
                       x ^= (1<<id[i-1][j]);
                       if(j)
                       x ^= (1<<id[i][j-1]);
                       if(i != 2)
                       x ^= (1<<id[i+1][j]);
                       if(j != 2)
                       x ^= (1<<id[i][j+1]);

                       if(mk[x])continue;
                       //cout<<x<<"\n";
                       mk[x] = true;

                       cola.push(x);
                       cost[x] = cost[node] + 1;
                    }
            }
        }

        int main()
        {
            ios_base::sync_with_stdio(0), cin.tie(0);
            int t;cin>>t;
            while(t--){
            memset(mk , 0 , sizeof(mk));
              int c = 0;
              for(int i = 0 ; i < 3 ; i++)
                 for(int j = 0 ; j < 3 ; j++)
                    id[i][j] = c++;

              for(int i = 0 ; i < 3 ; i++)
                 for(int j = 0 ; j < 3 ; j++){
                    cin>>M[i][j];
                    if(M[i][j] == '*')
                       node |= (1 << id[i][j]);
                 }
              //cout<<node<<"\n";
              bfs();
              cout<<cost[0]<<"\n";
            }
        }
