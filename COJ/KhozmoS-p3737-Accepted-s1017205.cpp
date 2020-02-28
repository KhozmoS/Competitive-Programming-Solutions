#include <bits/stdc++.h>

using namespace std;
const int MAXN = 111111;
typedef long long LL;

LL A , B;

LL arrA[MAXN];
LL arrB[MAXN];
LL TA[MAXN];

void tabla()
{
  TA[1] = arrB[1];

  for(int i = 2 ; i <= B ; i++)
  TA[i] = TA[i - 1] + arrB[i];

}
LL binary(int x)
{
    int ini = 1;
    int fin = B;

    while(fin - ini > 3)
    {
      int mit = (fin + ini) / 2;
      if(arrB[mit] >= x)
      fin = mit;
      else
      ini = mit;
    }
    for(int i = ini ; i <= fin ; i++)
    {
      if(arrB[i] >= x)
      return i;
      if(i == fin)
      return B;
    }

}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>A>>B;

    for(int i = 1 ; i <= A ; i++) cin>>arrA[i];

    for(int i = 1 ; i <= B ; i++) cin>>arrB[i];

    sort(arrB + 1 , arrB + B + 1);
    tabla();
    LL sol = 0;
    int k;
    for(int i = 1 ; i <= A ; i++)
    {
       k = i;
       LL pos = binary(arrA[i]);
       //cout<<k<<") "<<pos<<" ";
       LL suma = TA[B] - TA[pos - 1];
       LL sumb = TA[pos - 1];

       LL part1 = abs((arrA[i] * (B - pos + 1)) - suma);
       LL part2 = abs((arrA[i] * (pos - 1)) - sumb);

       sol += (part1 + part2);
       //cout<<part1 + part2<<" ";
       //cout<<"\n";
    }
    //cout<<"\n";
    cout<<sol<<"\n";
    return 0;
}
