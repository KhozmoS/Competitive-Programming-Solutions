#include <bits/stdc++.h>

using namespace std;
const int MAXN = 1111111;

int N ,M;
int p[MAXN];


struct trio{
  int a , b , c;
  trio(){}
  trio(int a , int b , int c):a(a) , b(b) , c(c){}

  bool operator < (const trio &X) const {
   return c > X.c;
  }
};

trio arist[MAXN];

int find(int nod)
{
    if(p[nod] == nod) return nod;

    return p[nod] = find(p[nod]);
}

int main()
{

    ios_base::sync_with_stdio(0);cin.tie(0);

     while(cin>>N>>M && (N != 0 && M != 0))
     {
         int cont = 1; int sol = 100000000;

        for(int i = 0 ; i < N ; i++) p[i] = i;

        for(int i = 0 ; i < M ; i++)
        {
          int x , y , z;
          cin>>x>>y>>z;
          arist[i] = trio(x , y , z);
        }
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
        if(cont == N)
        cout<<sol<<"\n";
        else cout<<"IMPOSSIBLE\n";
     }



    return 0;
}
