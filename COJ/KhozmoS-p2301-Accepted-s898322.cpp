#include <bits/stdc++.h>
#define MAXN 1000007
using namespace std;
int ABX[MAXN];
int ABY[MAXN];
int  mayx , menx , mayy , meny ;

void updatex(int pos , int val)
{
    for(int i = pos ; i < MAXN ; i += (i & -i))
        ABX[i] += val;
}
int sumx(int a , int b)
{
    int suma = 0;
    int sumb = 0;
    a--;
    for(int i = a ; i > 0 ; i -= (i & -i))
    {
        suma += ABX[i];
    }
    for(int i = b ; i > 0 ; i -= (i & -i))
    {
        sumb += ABX[i];
    }
    return sumb - suma;

}
void updatey(int pos , int val)
{
    for(int i = pos ; i < MAXN ; i += (i & -i))
        ABY[i] += val;
}
int sumy(int a , int b)
{
    int suma = 0;
    int sumb = 0;
    a--;
    for(int i = a ; i > 0 ; i -= (i & -i))
    {
        suma += ABY[i];
    }
    for(int i = b ; i > 0 ; i -= (i & -i))
    {
        sumb += ABY[i];
    }
    return sumb - suma;

}
int x , y , xa , xb , xc , ya , yb , yc ,n;
string cad ,igual;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tc ,q;
    cin>>tc;
    while(tc--){
    cin>>xa>>ya>>xb>>yb>>xc>>yc;
    mayx = max(max(xa , xb), xc);
    //cout<<mayx<<"\n";
    menx = min(min(xa , xb), xc);
    //cout<<menx<<"\n";
    mayy = max(max(ya , yb), yc);
    meny = min(min(ya , yb), yc);
    updatex(menx + 1 , 1);
    updatex(mayx ,-1);
    updatey(meny + 1, 1);
    updatey(mayy ,-1);
    }
    cin>>q;
    while(q--){
    cin>>cad>>igual>>n;
    if(cad == "x")
        cout<<sumx(1 , n)<<"\n";
    else
        cout<<sumy(1 , n)<<"\n";
    }
    return 0;
}
