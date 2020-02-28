#include <bits/stdc++.h>

using namespace std;
const int MAXN = 10000003;
typedef pair < int , int > p;

p ar[MAXN];

int distancia(p p1 , p p2)
{
   return sqrt(pow(p2.first - p1.first, 2) + pow(p2.second - p1.second , 2));
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t;

    cin>>t;

    while(t--)
    {
        int mend = 1000000005;
        int n; cin>>n;
        for(int i = 0 ; i < n ; i++)
        {
            p punto;
            int x , y;
            cin>>x>>y;
            punto.first = x;
            punto.second = y;
            ar[i] = punto;
        }
         sort(ar , ar + n);
         for(int i = 0 ; i < n ; i++)
         {
           int ver = 1;
           while(ver < 10 && i + ver < n)
           {
               if(distancia(ar[i] , ar[i + ver]) < mend)
               mend = distancia(ar[i] , ar[i + ver]);

               ver++;
           }
         }
         cout<<mend<<"\n";
    }
    return 0;
}
