#include <bits/stdc++.h>

using namespace std;


#define PB push_back
#define db long double
typedef long long ll;
typedef vector <int> vi;

const db eps = 1e-9;
typedef pair <db , db> p;


p p1 , p2;

p s;

db sq(db x)
{
    return x*x;
}
db dist(p a , p b)
{

   return sqrt(sq(a.first-b.first) + sq(a.second-b.second));
}
void f()
{
  while(dist(p1 , p2) > eps)
  {
        p med;
        med.first = (p1.first+p2.first)/2.0;
        med.second = (p1.second+p2.second)/2.0;

        if(dist(s , p1) <= dist(s , p2))
            p2.first = med.first , p2.second = med.second;
        else
            p1.first = med.first , p1.second = med.second;
  }
  cout<<setprecision(3)<<fixed<<p1.first<<" "<<p1.second<<" "<<dist(s , p1)<<"\n";
}

int main()
{
   ios_base::sync_with_stdio(0);cin.tie(0);
   cin>>s.first>>s.second;
   cin>>p1.first>>p1.second>>p2.first>>p2.second;
   while(p1.first < 1e18 && p1.second < 1e18 && p1.first > -1e18 && p1.second > -1e18)
   {
       p1.first = p1.first*2.0-p2.first;
       p1.second = p1.second*2.0-p2.second;
   }
   while(p2.first < 1e18 && p2.second < 1e18 && p2.first > -1e18 && p2.second > -1e18)
   {
       p2.first = p2.first*2.0-p1.first;
       p2.second = p2.second*2.0-p1.second;
   }
   f();
}
