#include <bits/stdc++.h>

using namespace std;
const int MAXN = 1111111;
long long sol = 1;
long long n;
long long ar[30];


int main() {

 ios_base::sync_with_stdio(0);cin.tie(0);
   cin>>n;
   if(n % 3 == 1 || n % 3 == 2)
   cout<<"Kedir wins\n";
   else
   cout<<"Victor wins\n";
	return 0;
}
