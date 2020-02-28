#include <bits/stdc++.h>

using namespace std;
const int MAXN = 2005;
typedef pair <int , int > point;

int p[MAXN];
int n;

int find(int h)
{
  if(h == p[h])
  return h;

  return p[h] = find(p[h]);
}
struct trio{
int a , b ; int c;
trio(){}
trio(int a , int b , int c):a(a) , b(b) , c(c){}


bool operator < (const trio &X)const {

  return c < X.c;
}

};
trio arist [4000004];
point arr[MAXN];
bool flag;
int main()
{
  //ios_base::sync_with_stdio(0);cin.tie(0);
    int cost; cin>>n>>cost;
      int con = 0;
      int sol = 0;
     for(int i = 0 ; i < n ; i++)
     {
      cin>>arr[i].first>>arr[i].second;
     }
     for(int  i = 0 ; i < n ; i++)
     p[i] = i;
     for(int i = 0 ; i < n - 1 ; i++)
     for(int j = i + 1 ; j < n ; j++)
     {
      int c = pow(arr[i].first - arr[j].first , 2) + pow(arr[i].second - arr[j].second , 2);
      if(cost <= c){
       arist[con] = trio(i , j , c);
       con++;
       }
     }
      sort(arist , arist + con);
       int cont = n;
      for(int i = 0 ; i < con && n > 1 ; i++)
      {
        int x = find(arist[i].a);
        int y = find(arist[i].b);
        if(x != y)
        {
          n--;
          p[x] = y;
          sol += arist[i].c;
        }

      }

      //cout<<n<<"\n";
      if(n > 1)
      cout<<"-1\n";

      else cout<<sol<<"\n";

    //  cout<<sol;
    return 0;
}
