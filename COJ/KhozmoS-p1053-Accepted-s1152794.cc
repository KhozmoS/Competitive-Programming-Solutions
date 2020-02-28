#include <bits/stdc++.h>

using namespace std;


typedef long long ll;
const int MAX = 1e2 + 5;
ll p[MAX];
vector <ll> ar;
struct par{
 ll a , b;
 par(){}
 par(int a , int b):a(a) , b(b){}

 bool operator < (const par &X)const {
  return p[a] * ar[b] > p[X.a] * ar[X.b];
 }
};

priority_queue <par> Q;

set <ll> S;
int n , pos;
void f()
{
    while(true){
     par s = Q.top();Q.pop();
     ll num = p[s.a] * ar[s.b];
     if(S.find(num) == S.end()){
        ar.push_back(num);
        S.insert(num);
     }
     Q.push(par(s.a , s.b+1));
     if(ar.size() >= pos + 5) return;
    }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  while(cin>>n>>pos){
  S.clear();
  while(!Q.empty()) Q.pop();
  ar.clear();

  for(int i = 0 ; i < n ; i++)
    cin>>p[i];

  ar.push_back(1);
  for(int i = 0 ; i < n ; i++)
    Q.push(par(i , 0));
  f();
 // sort(ar.begin() , ar.end());
  cout<<ar[pos]<<"\n";
  }
}
