#include <bits/stdc++.h>

using namespace std;
const int MAX = 1e4+5;


const int NUM = 6;
const double inf = 1e9;

double pi = 3.14;
double r;
double sin_60 = 0.86602540378443864676372317075294;
double sq(double x)
{return x*x;}
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t;
    cin>>t;
    while(t--){
    double r;cin>>r;

	double A_t = sq(2*r) * sin_60 / 2;
	double A_sec = (pi * 60.0 * r*r) / 360.0;
	cout<<setprecision(2)<<fixed<<A_t - (3*A_sec)<<"\n";
    }
}
