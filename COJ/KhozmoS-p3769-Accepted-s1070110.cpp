//KhozmoS
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int mod = 0;
typedef pair <int , int> par;
typedef pair <par , int> trio;
typedef map <string , int> mapa;
const int MAXN = 105;
vector <int> v;
queue <int> cola;
int ar[MAXN];
int M[MAXN][MAXN];
//int a , b , c;
string cad;

int main()
{
   ios_base::sync_with_stdio(0);cin.tie(0);
  double a; double b;
  int n;double solt = -1;
   cin>>n;
    while(n--)
    {
     cin>>a>>b;
      double sol = ((a * 0.7) + (b * 0.3));
      solt = max(solt , sol);
      //printf("%.2lf" , sol);

    }
     printf("%.2lf" , solt);
    return 0;
}
