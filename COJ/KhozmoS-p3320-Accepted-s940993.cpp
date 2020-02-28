#include <bits/stdc++.h>

using namespace std;
//map <string , bool> m;
typedef long long LL;
vector <LL> cuad;
void tabla()
{
    for(int i = 1 ; i <= 100000 ; i++)
    cuad.push_back(i * i);
}

LL sum(LL n)
{
	return (n & 1) ? (n + 1) / 2 * n : (n / 2) * (n + 1);
}

LL n , m;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
  tabla();
   while(cin>>n>>m)
   {
       if(n == 0 && m == 0) break;
       LL sol = sum(m) - sum(n - 1);
       for(int i = 0 ; i <= 100000 ; i++)
       {
           if(cuad[i] >= n && cuad[i] <= m)
           sol -= cuad[i];
           if(cuad[i] > m)
           break;
       }
       cout<<sol<<"\n";
   }
    return 0;
}
