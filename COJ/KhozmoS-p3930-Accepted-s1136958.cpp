#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int MAX = 1e5 + 6;
int pxn = 1; int pxp = 1; int pyn = 1; int pyp = 1;
ll xn[MAX] ;
ll yne[MAX];
ll xs[MAX];
ll ys[MAX];

ll ta1[MAX];
ll ta2[MAX];
ll ta3[MAX];
ll ta4[MAX];

int bin1(int in , int fn , ll v)
{
    int mt = (fn + in) >> 1;
    if(fn - in < 5)
    {
      for(int i = in ; i <= fn ; i++)
       if(xn[i] > v)
       return i - 1;
       return pxn;
    }
    if(xn[mt] <= v)
     return bin1(mt , fn , v);
    return bin1(in , mt , v);
}
int bin2(int in , int fn , ll v)
{
    int mt = (fn + in) >> 1;
    if(fn - in < 5)
    {
      for(int i = in ; i <= fn ; i++)
       if(xs[i] > v)
       return i - 1;
       return pxp;
    }
    if(xs[mt] <= v)
     return bin2(mt , fn , v);
    return bin2(in , mt , v);
}
int bin3(int in , int fn , ll v)
{
    int mt = (fn + in) >> 1;
    if(fn - in < 5)
    {
      for(int i = in ; i <= fn ; i++)
       if(yne[i] > v)
       return i - 1;
       return pyn;
    }
    if(yne[mt] <= v)
     return bin3(mt , fn , v);
    return bin3(in , mt , v);
}
int bin4(int in , int fn , ll v)
{
    int mt = (fn + in) >> 1;
    if(fn - in < 5)
    {
      for(int i = in ; i <= fn ; i++)
       if(ys[i] > v)
       return i - 1;
       return pyp;
    }
    if(ys[mt] <= v)
     return bin4(mt , fn , v);
    return bin4(in , mt , v);
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n , w;

    cin>>n;
    while(n--)
    {
      ll x , y;
      cin>>x>>y;
      if(x < 0) xn[pxn++] = x;
      else xs[pxp++] = x;
      if(y < 0) yne[pyn++] = y;
      else ys[pyp++] = y;
    }
    //cout<<pxn<<"\n";
    pxn--;pxp--;pyn--;pyp--;
     //cout<<xn[1]<<"\n";
    sort(xn + 1 , xn + pxn + 1);
    sort(xs + 1 , xs + pxp + 1);
    sort(yne + 1 , yne + pyn + 1);
    sort(ys + 1 , ys + pyp + 1);
    //cout<<xn[1]<<"\n";
    for(int i = 1 ; i <= pxn ; i++)
      ta1[i] += (xn[i] + ta1[i - 1]);
    for(int i = 1 ; i <= pxp ; i++)
      ta2[i] += (xs[i] + ta2[i - 1]);
    for(int i = 1 ; i <= pyn ; i++)
      ta3[i] += (yne[i] + ta3[i - 1]);
    for(int i = 1 ; i <= pyp ; i++)
      ta4[i] += (ys[i] + ta4[i - 1]);
     //cout<<ta1[1]<<" "<<pxn<<"\n";
    cin>>w;
    long long ans = 0;
    while(w--)
    {
      ans = 0;
      long long x , y;
      cin>>x>>y;
      if(pxn)
      {
        int pos = bin1(1 , pxn , x);
        ans += abs(ta1[pos] - (pos * x));
        ans += abs((ta1[pxn] - ta1[pos]) - (x * (pxn - pos)));
        //cout<<ta1[pos]<<" "<<pos<<"\n";
      }

     // cout<<ans<<"\n";
      if(pxp)
      {
        int pos = bin2(1 , pxp , x);
        ans += abs(ta2[pos] - (pos * x));
        ans += abs((ta2[pxp] - ta2[pos]) - (x * (pxp - pos)));
      }
      // cout<<ans<<"\n";
      if(pyn)
      {
        int pos = bin3(1 , pyn , y);
        ans += abs(ta3[pos] - (pos * y));
        ans += abs((ta3[pyn] - ta3[pos]) - (y * (pyn - pos)));
      }
      // cout<<ans<<"\n";
      if(pyp)
      {
        int pos = bin4(1 , pyp , y);
        ans += abs(ta4[pos] - (pos * y));
        ans += abs((ta4[pyp] - ta4[pos]) - (y * (pyp - pos)));
      }
      cout<<ans<<"\n";
    }
}
