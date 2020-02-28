#include <bits/stdc++.h>

using namespace std;
 typedef long long LL;
 const int MAXN = 1005;
 int MA[MAXN][MAXN];
 int TA[MAXN][MAXN];
int cont[MAXN];
 int N;
 int posi , posj;
 
int main()
{
   ios_base::sync_with_stdio(0);cin.tie(0);
   LL A , B;
   cin>>A>>B;
   cout<<(A+B) + (A-B) + (B+A) + (B-A)<<"\n";
    return 0;
}
