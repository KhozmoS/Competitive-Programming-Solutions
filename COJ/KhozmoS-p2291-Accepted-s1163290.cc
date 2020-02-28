#include <bits/stdc++.h>

using namespace std;


const int MAX = 1e8+10;
bitset <MAX> mk;

typedef pair <int , int> point;

const int mx[] = {0 , 1 , 0 , -1},
          my[] = {1 , 0 , -1 , 0};

void criba()
{
    for(int i = 2 ; i * i < MAX ; i++)
        if(mk[i] == 0) for(int j = i * i ; j < MAX ; j += i)
                        mk[j] = 1;
}
vector <point> Q;
const int maxn = 1e5 +5;
int Qx[maxn] , Qy[maxn];


vector <point> ans;

int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;
  mk[1] = 1;
  criba();
  //for(int i = 1 ; i <= 11 ; i++)cout<<mk[i]<<" ";
  cin>>t;

  int id = 1;
  int MAXK = 0;
  while(t--)
  {
      int K;cin>>K;
      Q.push_back(point(K , id++));
      MAXK = max(MAXK , K);
  }
      sort(Q.begin() , Q.end());
      int act = 0;
      int dir = 0;
      int sz = Q.size();

      for(int i = 1 ; i <= MAXK ; i++)
      {

          Qx[act] += mx[dir];
          Qy[act] += my[dir];

          if(mk[i] == 0) dir++;

          dir %= 4;


          while(act < sz && i >= Q[act].first)
             act++;


          if(act == sz) break;
      }

      for(int i = 0 ; i < sz ; i++)
          ans.push_back(point(Q[i].second , i));

      sort(ans.begin() , ans.end());

      for(int i = 1 ; i < maxn ; i++)
      {
          Qx[i] += Qx[i-1];
          Qy[i] += Qy[i-1];
      }
      for(int i = 0 ; i < ans.size() ; i++)
         cout<<Qx[ans[i].second]<<" "<<Qy[ans[i].second]<<"\n";

}
