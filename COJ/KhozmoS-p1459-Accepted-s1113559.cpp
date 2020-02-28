#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
vector<ll> h,p;
string g;
ll calc_hash(int s, int e){return (h[e]-h[s]*p[e-s]);}

void prepararHash(){
 h.push_back(5381); p.push_back(1);
    for(int i = 1;i<=g.length();i++) h.push_back(h[i-1]*33+ (g[i-1]-'a')+1);
    for(int i =1;i<=g.length();i++) p.push_back(p[i-1]*33);
}

bool compare(int A, int B){
int s=0, e = g.length() - max(A,B)+1,m;
  while(e-s>1){
    m=(s+e)/2;
    if(calc_hash(A,A+m)==calc_hash(B,B+m)) s=m;
    else e=m;
  }
 return g[A+s]< g[B+s];
}


int main()
{
    cin>>g;
    int pos=0,len= g.length();
    g+=g;
    prepararHash() ;
    ll key,mayor = calc_hash(0, len);
    int sa[len+1];
    for(int i =0; i< len+1; i++) sa[i]=i;
    sort(sa,sa+len+1,compare);
    cout<<sa[len]<<"\n";
    return 0;
}

