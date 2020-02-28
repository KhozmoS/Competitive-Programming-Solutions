#include<bits/stdc++.h>

using namespace std;
 typedef long long LL;
 vector <int> P;
 const int MAXN = 10000003;
 int AB[MAXN];
 bool cmp[MAXN];
 vector <int> ver;
bool pal(int n){
    int mirror = 0;
    int aux = n;

    while(aux > 0){
        int d = aux % 10;
        mirror = mirror * 10 + d;
        aux /= 10;
    }
    if(mirror == n)
        return 1;
    return 0;
}
void Criba(){
    cmp[1] = cmp[0] = 1;
    for(int i = 4; i < MAXN; i += 2)
        cmp[i] = 1;

    for(int i = 3; i * i < MAXN; i += 2){
        if(!cmp[i]){
            for(int k = i * i; k < MAXN; k += 2 * i)
                cmp[k] = 1;
        }
    }

    P.push_back(2);
    for(int i = 3; i < MAXN; i += 2){
        if(!cmp[i])
        if(pal(i))
            P.push_back(i);

    }
}


 void update(int pos , int value)
{
    for(int i = pos ; i <= MAXN ; i += (i & -i))
        AB[i] += value;

}
int sum(int a , int b)
{
    int suma = 0;
    int sumb = 0;
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
   Criba();

   //cout<<pri.size();
   int n;
   cin>>n;
   for(int i = 0 ; i < 781 ; i++){
       update(P[i] , 1);
       //cout<<pri[i]<<'\n';
       }
   while(n--)
   {
       int a , b;
       cin>>a>>b;
       cout<<sum(a , b)<<'\n';
   }
    return 0;
}
