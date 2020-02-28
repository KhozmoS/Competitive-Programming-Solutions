#include <bits/stdc++.h>

using namespace std;


#define f first
#define s second
const int MAX = 1e6 + 5;;
typedef pair <int , int> par;
int freq[MAX] , ans1 , ans2 , in , fn;
par ar[MAX];
bool flag;
map <int , bool> mk;


int main()
{
    int men = 1e9 + 5;
    ios_base::sync_with_stdio(0);cin.tie(0);

    int k;cin>>k;
    int cant = 0;
    for(int i = 1 ; i <= k ; i++)
    {
        int c;cin>>c;
        if(!c) flag = true;

        while(c--)
        {
            int x;cin>>x;
            ar[++cant] = par(x , i);
        }
    }
    sort(ar + 1 , ar + cant + 1);
    in = 1 , fn = 1;
    int df = 1;
    freq[ar[in].s]++;
    mk[ar[in].s] = true;
    while(in <= cant && fn <= cant)
    {
       if(df < k){
          fn++;
          if(mk.find(ar[fn].s) == mk.end())
          {
              mk[ar[fn].s] = true;
              df++;
          }
          freq[ar[fn].s]++;
       }
       else if(df == k)
       {
          if(men > (ar[fn].f - ar[in].f))
          {
              men = (ar[fn].f - ar[in].f);
              ans1 = ar[in].f;
              ans2 = ar[fn].f;
          }
          freq[ar[in].s]--;
          if(!freq[ar[in].s]){ mk[ar[in].s] = false;df--;mk.erase(ar[in].s);}
          in++;
       }

    }
    if(flag) cout<<"-1\n";

    else cout<<ans1<<" "<<ans2<<"\n";

}
/*
2
3 10 13 100000
3 11 999 998
*/
