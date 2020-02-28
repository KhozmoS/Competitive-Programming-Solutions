#include<bits/stdc++.h>

using namespace std;
const int MAXN = 11111111;
int N , M;
int p[MAXN];

struct trio{
    int a, b, c;
    trio(){}
    trio(int a, int b, int c): a(a),b(b),c(c){}

    bool operator < (const trio &X)const {
        return c > X.c;
    }

};

int find(int nod)
{
    if(nod == p[nod])
        return nod;

    return p[nod] = find(p[nod]);
}



trio arist[MAXN];
int cont = 1;

int main()
{
  while(cin>>N>>M && (N != 0 && M != 0))
  {
      int sol = 1000000000;
      for(int i = 0 ; i < M ; i++)
      {
          int x , y , z;
          cin>>x>>y>>z;
          arist[i] = trio(x , y , z);
      }
      for(int i = 0 ; i < N ; i++) p[i] = i;
      sort(arist , arist + M);

      for(int i = 0 ; i < M ; i++)
      {
          int x = find(arist[i].a);
          int y = find(arist[i].b);
          if(x != y)
          {
            p[x] = y;
            if(sol > arist[i].c) sol = arist[i].c;

            cont++;
          }

      }
        if(cont != N) cout<<"IMPOSSIBLE\n";

        else cout<<sol<<"\n";

        cont = 1;

    }

return 0;
}
