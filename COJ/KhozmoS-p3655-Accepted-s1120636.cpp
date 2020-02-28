#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

typedef unsigned long long int ULL;
const double INF = 10000000000000000;

struct point{
	double x, y;
};

bool f(const point & p1, const point & p2){
	return p1.x < p2.x;
}

double c_dist(const point & p1, const point & p2){
	return (p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y);
}

double comb(const vector<point> & p, const int & l, const int & m, const int & h, const double & dist_l, const double & dist_r){
	double dist = min(dist_l, dist_r);
	double dist_t = dist;
	
	double line = (p[m].x + p[m+1].x)/2.0;

	for (int i = m+1; i <= h && p[i].x < line+dist; i++)
		for (int j = m; j >= l && p[j].x > line-dist; j--)
			dist_t = min(c_dist(p[i], p[j]), dist_t);
	
	return dist_t;
}

double div(const vector<point> & p, const int & l, const int & h){
	if (h <= l) return INF; //done dividing
	
	double dist_l, dist_r, dist_t;
	
	int m = (l+h)/2;
	dist_l = div(p, l, m); dist_r = div(p, m+1, h); //left half, right half
	dist_t = comb(p, l, m, h, dist_l, dist_r); //both halves
	
	return dist_t;
}

int main(){
		vector<point> p;
		point temp; temp.x = temp.y = 0;
		int N, test, d;
		double x_c, y_c;
	//ifstream in("in.txt"); ofstream out("out.txt");
	
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> test;
	while (test--){
		cin >> N;
		p.clear(); p.assign(N, temp);
		
		for (int i = 0; i < N; i++) cin >> p[i].x >> p[i].y;
		sort(p.begin(), p.end(), f);
        
		d = sqrt(div(p, 0, N-1));
  
		cout << d << "\n";
	}
	
	return 0;
}
