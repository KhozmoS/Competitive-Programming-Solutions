#include <bits/stdc++.h>

using namespace std;
const int MAXN = 1000007;
typedef long long LL;
typedef pair <int , int > par;
par A[MAXN];
LL AB[MAXN];
LL sol , N;
void update(int pos , LL value)
{
    for(int i = pos ; i <= N ; i += (i & -i))
        AB[i] += value;

}
int sum(int a , int b)
{
    LL suma = 0;
    LL sumb = 0;
    a--;
    for(int i = a ; i > 0 ; i -= (i & -i))
    {
      suma += AB[i];
    }
    for(int i = b ; i > 0 ; i -= (i & -i))
    {
      sumb += AB[i];
    }
    return sumb - suma;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>N;
    for(int i = 1 ; i <= N ; i++)
    {
        par p;
        int a;
        cin>>a;
        p.first = a; p.second = i;
        A[i] = p;
    }
     sort(A + 1 , A + N + 1);
  //     update(1 , 1);
     for(int i = 1 ; i <= N ; i++)
     {
         int pos = A[i].second;

         sol += (sum(1 , N) - sum(1 , A[i].second));
         update(pos , (LL)1);
     }
     cout<<sol<<"\n";
    return 0;
}
