#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000000005;
const int MAXN = 111;
int n;

int ar[MAXN];
double x[MAXN]; double y[MAXN];
int p[MAXN];

struct trio{
 int a , b; double c;
 trio(){}
 trio(int a , int b , double c):a(a) , b(b) , c(c){}

 bool operator < (const trio &X)const {
  return c < X.c;
 }

};

trio arist[1111111];

double distancia(double x , double x1 , double y , double y1)
{
  double difx = (x - x1) * (x - x1);
  double dify = (y - y1) * (y - y1);

  return sqrt(difx + dify);
}
//kruscal
int find(int nod)
{
   if(nod == p[nod])
   return nod;

   return p[nod] = find(p[nod]);
}
int main()
{

//    generar();
  ios_base::sync_with_stdio(0);cin.tie(0);

   cin>>n;
     for(int i = 0 ; i < n ; i++)
     p[i] = i;

    for(int i = 0 ; i < n ; i++)
    {
        cin>>x[i]; cin>>y[i];
    }
    double mst = 0;
    int cont = 0;
    for(int i = 0 ; i < n - 1 ; i++)
    for(int j = i + 1 ; j < n ; j++)
    {
      double z = distancia(x[i] , x[j] , y[i] , y[j]);
      arist[cont] = trio(i , j , z);
      cont++;
    }
    sort(arist , arist + cont);

    for(int i = 0 ; i < cont ; i++)
    {
        int x = find(arist[i].a);
        int y = find(arist[i].b);
        if(x != y)
        {
          p[x] = y;
          mst += arist[i].c;
        }
    }
    printf("%.2lf\n" , mst);
    return 0;
}
