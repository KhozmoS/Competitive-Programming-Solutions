#include <bits/stdc++.h>

using namespace std;
const int MAX = 1e4+5;

#define x first.first
#define y first.second
#define z second

const int NUM = 6;
const double inf = 1e9;

typedef pair <double , double> II;
typedef pair <II , double> point;
point ar[MAX];

double dist(point a , point b)
{
    double sqx = (a.x - b.x) * (a.x - b.x);
    double sqy = (a.y - b.y) * (a.y - b.y);
    double sqz = (a.z - b.z) * (a.z - b.z);
    return sqrt(sqx + sqy + sqz);
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
	int N;
	while (cin>>N && N) {
		 priority_queue <double> Q;

		 for(int i = 0 ; i< 6 ; i++) Q.push(inf);

		 for(int i = 0 ; i < N ; i++)
            cin>>ar[i].x>>ar[i].y>>ar[i].z;

         sort(ar , ar + N);
         int in = 0;
         for(int i = 0 ; i < N ; i++)
         {
             while(ar[i].x - ar[in].x > Q.top()) in++;

             for(int j = in ; j < i ; j++)
             {
                 double cur = dist(ar[i] , ar[j]);
                 if(cur < Q.top())
                 {
                     Q.pop();
                     Q.push(cur);
                 }
             }
         }
         double ans = 0;
         while(!Q.empty())
            ans += Q.top() , Q.pop();
         cout<<setprecision(2)<<fixed<<ans<<"\n";
	}
}
