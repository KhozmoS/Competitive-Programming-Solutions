#include <bits/stdc++.h>


using namespace std;

#define f first
#define s second

typedef pair <double , double> point;
const double inf = 10000000000000000;

double dis(const point & p1 , const point & p2)
{
    double sqa = (p1.f - p2.f) * (p1.f - p2.f);
    double sqb = (p1.s - p2.s) * (p1.s - p2.s);

    return sqa + sqb;
}

double comb(const vector <point> & p , const int & in , const int & mt , const  int & fn , const double & m_dis)
{
   double t_dis = m_dis;

   double line = (p[mt].f + p[mt + 1].f) / 2.00;

   for(int i = mt + 1; i <= fn && p[i].f < line + m_dis ; i++)
     for(int j = mt ; j >= in && p[j].f > line - m_dis ; j--)
       t_dis = min(t_dis , dis(p[i] , p[j]));

  return t_dis;
}


double divide(const vector <point> & p , const int & in , const int & fn)
{
    if(fn <= in) return inf;

    int mt = (in + fn) >> 1;
    double l_dis = divide(p , in , mt);
    double r_dis = divide(p , mt + 1 , fn);

    double t_dis = comb(p , in , mt , fn , min(l_dis , r_dis));

    return t_dis;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(false);
	point temp = point(0 , 0);
	int n, t, conquer;
	double x_c, y_c;

    cin>>t;

   while (t--){
		cin >> n;
        vector<point> p(n);
		p.clear(); p.assign(n, temp);

		for (int i = 0; i < n; i++) cin >> p[i].f >> p[i].s;

		sort(p.begin(), p.end());

		conquer = sqrt(divide(p, 0, n-1));

		cout << conquer << "\n";
	}
    return 0;
}
