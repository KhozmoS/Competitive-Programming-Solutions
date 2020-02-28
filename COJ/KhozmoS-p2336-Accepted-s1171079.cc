#include <bits/stdc++.h>

using namespace std;
const int MAX = 1e6+5;

const int NUM = 6;

struct point {
	double  x, y ,z;
	bool operator<(const point& B) const {
		return y == B.y ? x == B.x ? z < B.z : x < B.x : y < B.y;
	}
} P[MAX];
bool cmpX(point A, point B) {
	return A.x == B.x ? A.y == B.y ? A.z < B.z : A.y < B.y : A.x < B.x;
}
double dist(point A, point B) {
	double  x = A.x - B.x;
	double  y = A.y - B.y;
	double  z = A.z - B.z;
	return sqrt(x*x + y*y + z*z);
}
int main() {
	int N;
	while (cin>>N && N) {
		priority_queue<double> h;
		for(int i=0; i<NUM; i++)h.push(1e12);

		for (int i = 0; i < N; i++)	cin>>P[i].x>>P[i].y>>P[i].z;

		sort(P, P + N, cmpX);

		set<point> S;
		set<point>::iterator up, lo;

		int k = 0;
		for (int i = 0; i < N; i++) {
			for (; P[i].x - P[k].x > h.top(); k++){ S.erase(S.find(P[k]));}
			point c = P[i];
			up = upper_bound(S.begin(), S.end(), (point){0, ceil(c.y + h.top() + 1) , 0});
			lo = lower_bound(S.begin(), S.end(), (point){0, floor(c.y - h.top() - 1) , 0});
			for (; lo != up; lo++){
				double dd = dist(*lo, c);
				h.push(dd);
				if((int)h.size() > NUM)h.pop();
			}
			S.insert(P[i]);
		}
		double ans1 = 0;
		//other
        while(!h.empty()){
			ans1+=h.top();
			h.pop();
		}

/*
		for (int i = 0; i < N; i++) {
			for (; P[i].x - P[k].x > h.top(); k++) S.erase(S.find(P[k]));
			point c = P[i];
			up = upper_bound(S.begin(), S.end(), (point){0, ceil(c.y + h.top() + 1) , 0});
			lo = lower_bound(S.begin(), S.end(), (point){0, floor(c.y - h.top() - 1) , 0});
			for (; lo != up; lo++){
				double dd = dist(*lo, c);
				h.push(dd);
				if((int)h.size() > NUM)h.pop();
			}
			S.insert(P[i]);
		}*/
/*
        double ans2 = 0.0;
		while(!h.empty()){
			ans2+=h.top();
			h.pop();
		}*/
		printf("%.2lf\n", ans1);
	}
}
