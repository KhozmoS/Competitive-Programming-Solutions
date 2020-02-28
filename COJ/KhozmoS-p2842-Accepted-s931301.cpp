#include<bits/stdc++.h>

using namespace std;
 typedef long long LL;
 vector <int> pri;
 const int MAXN = 10000003;
 int AB[MAXN];
 bool comp[MAXN];
 vector <int> ver;
 bool pal(int x)
 {
     int cont = 0;
     while(x != 0)
     {
         ver.push_back(x % 10);
         cont++;
         x /= 10;
     }
      int i = 0; int j = cont - 1; bool flag = true;
      while(i < j)
      {
          if(ver[i] != ver[j]){
          flag = false;
          break;
          }
          i++; j--;
      }
      ver.clear();
      return flag;
 }
  void criba()
  {
	for(int i = 4 ; i < MAXN ; i += 2)
	comp[i] = true;
    for(LL i = 3 ; i < MAXN / 2 ; i += 2)
    {
      if(!comp[i])
      {
      for(LL j = i * i ; j < MAXN ; j += i)
    	  comp[j] = true;
      }
    }
    pri.push_back(2);
    comp[1] = true;
    for(int i = 3 ; i < MAXN ; i += 2)
    {
    	if(!comp[i])
    	{
    	 if(pal(i))
    	 pri.push_back(i);
    	}
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
   criba();

   //cout<<pri.size();
   int n;
   cin>>n;
   for(int i = 0 ; i < 781 ; i++){
       update(pri[i] , 1);
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
