#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second


const int MAX = 1e4 + 5;
int a , c , m , x , q , n;
short f[MAX * 5];

typedef pair <short , int> par;
const int maxn = 1e4 + 5;
par ans[maxn * 5];


short bin(int in , int fn , int ind)
{
    int md = (in + fn) >> 1;

    if(fn - in <= 7)
    {
      for(int i = in; i <= fn ; i++)
       if(ans[i].s > ind)
        return ans[i].f;

        //return ans[md].f;
    }
    if(ans[md].s > ind)
        return bin(in , md , ind);

    return bin(md , fn , ind);
}
short mk[MAX];

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);

      while(cin>>a>>c>>m>>x>>q>>n){

		for(int i = 0 ; i < 10000 ; i++) mk[i] = -1;

        f[0] = x;
        mk[x] = 0;
        int ta = 1;
        int cs = 0;
        for(int i = 1 ;; i++){
          f[i] = (a * f[i - 1] + c) % m;
          if(mk[f[i]] != -1){ cs = mk[f[i]] ; break;}

          mk[f[i]] = i;
          ta++;
          /*if(ta >= MAX)
            break;*/
        }
        //cout<<"wa\n";
        m = ta;
        //m--;
        int tn = n;
       // cout<<m<<"\n";
        for(int i = 0 ; i < cs ; i++)
          ans[i] = make_pair(f[i] , 1);

        for(int i = cs ; i < m; i++)
        {
          int top = 0;
          if(tn <= m && i < tn)
            top = 1;
          else{
          n -= cs;
          int tc = m - cs;
          int j = i - cs;
          if(j < (n % tc))
          top = 1;

          top += n / tc;
          }
          ans[i] = make_pair(f[i] , top);
        }

        sort(ans , ans + m);

        for(int i = 1 ; i < m ; i++){
           ans[i].s += ans[i - 1].s;/*cout<<ans[i].s<<"\n";*/}
        //if(ans[m - 1].s <= n)
        //  ans[m - 1].s = n;


        while(q--)
        {
		//	int tc = m - cs;
            int ind;
            cin>>ind;
            ind--;
            /*if(ind >= cs){
              ind -= cs;
              ind %= tc;
              ind += cs;
		     }*/
           cout<<bin(0 , m , ind)<<"\n";
        }

}
    return 0;
}
/*
7 4 9 3 10 10
1
2
3
4
5
6
7
8
9
10
*/
