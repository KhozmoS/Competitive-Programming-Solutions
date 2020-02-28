#include <bits/stdc++.h>

using namespace std;
#define db double
#define pos first
#define h second

const int MAX = 1e4 + 5;
db eps = 1e-10;

typedef pair <db , db> build;

int n;
db cp;
build ar[MAX];
build center;

db dist(db x , db y , db x1 , db y1)
{
    db d1 = (x - x1) * (x - x1);
    db d2 = (y - y1) * (y - y1);
    return sqrt(d1 + d2);
}
db KhozmoS(db hip ,db kt)
{
    // h^2 - kt1^2 = kt2^2;
    return sqrt((hip * hip) - (kt * kt));
}

bool ver(db rad)
{
   db in = 0.0; db fn = 1e5;

     while(in + eps < fn)
     {
         db mt = (in + fn) / 2.0;
         int i = 0;
         for(; i < n ; i++)
         {
             if(dist(ar[i].pos - 0.5 , ar[i].h , mt , 0) > rad || dist(ar[i].pos + 0.5 , ar[i].h , mt , 0) > rad)
             {
                 if(ar[i].pos < mt)
                    fn = mt;
                 else
                    in = mt;
                 break;
             }
         }
         if(i == n) return true;
     }
     return false;
}
db bin(db in , db fn)
{
    db res = 1e14;
    while(fn - in > eps)
    {
        db mt = (in + fn) / 2.0;

        if(ver(mt)){
            fn = mt;
            res = min(mt , res);
        }
        else
            in = mt;

    }
    return res;
}

int main()
{
   ios_base::sync_with_stdio(0);cin.tie(0);
   cout<<setprecision(9)<<fixed;
   cin>>n;

   for(int i = 0 ; i < n ; i++)
   {
       db x , hi; cin>>x>>hi;
       ar[i] = build(x , hi);
   }
   sort(ar , ar + n);

   cout<<bin(0.0 , 1e9)<<"\n";
}
