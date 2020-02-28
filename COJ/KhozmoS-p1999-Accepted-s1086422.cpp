#include <set>
#include <cstdio>
#include <algorithm>

const int RAN = 1100;
const int q = 100000000;

using namespace std;
typedef pair<long long,bool>par;

struct cua{
        long long x, x1, y, y1;
        cua (long long a=0, long long b=0, long long c=0, long long d=0){
             x = a;
             y = b;
             x1 = c;
             y1 = d;
        }
}A[RAN];

struct tri{
        int x, id, m;
        tri(long long a = 0, int b = 0, bool c = 0){
            x = a;
            id = b;
            m = c;
        }
        bool operator <(const tri &R)
        const {
              return R.x > x;
        }
}B[RAN*3];

int n, c, c1;
long long ini, x, x1, y, y1, sol, mul;

multiset<par>S;
multiset<par>::iterator ii;

int main (){

    scanf ("%d", &n);
    for (int i = 1; i <= n; i++){
         scanf ("%lld %lld %lld %lld", &x, &y, &x1, &y1);
         x += q;
         x1 += q;
         y += q;
         y1 += q;
         A[i] = cua(x, y, x1, y1);
         B[++c] = tri(x, i, 0);
         B[++c] = tri(x1, i, 1);
    }

    sort (B+1,B+c+1);

    for (int i = 1; i <= c; i++){

         mul = 0;
         c1 = 0;
         for ( ii = S.begin(); ii != S.end(); ii++){
              if (c1==0)
                  ini = ii -> first;
              if (ii -> second == 0)
                  c1++;
               else {
                  c1--;
                  if (c1==0)
                      mul += (ii -> first - ini);
               }
         }

         sol += (mul * (B[i].x-B[i-1].x));

        int id = B[i].id;
        if (B[i].m == 0){
            S.insert (par(A[id].y1, 0));
            S.insert (par(A[id].y, 1));
         }
          else{
             S.erase (S.find(par(A[id].y1, 0)));
             S.erase (S.find(par(A[id].y, 1)));
          }
    }

    printf ("%lld\n", sol);

}
