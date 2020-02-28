#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

LL toll(string num)
{
  LL ret = 0;
  ret = (num[0] - '0');
  //cout<<ret<<num<<"\n";
  for(int i = 1 ; i < num.size() ; i++){
  if(num[i] != '.'){
  ret *= 10;
  ret += (num[i] - '0');
  }
  //else
  //ret *= 10;
  }

  return ret;
}
int N;
LL P , B;
LL ar[25];
map <LL , bool> mapa;
LL sol;
void F(int pos , LL sum)
{
    if(sum >= P && !mapa[sum]){
    mapa[sum] = true;
    sol++;
    }
    if(pos == N)
    return;

    F(pos + 1 , sum);
    F(pos + 1 , sum + (2 * ar[pos]));
}

int main()
{
  string a , b;
  ios_base::sync_with_stdio(0);cin.tie(0);
   cin>>N>>a>>b;

   P = toll(a); B = toll(b);

   P -= B;

   for(int i = 0 ; i < N ; i++){
   string x; cin>>x;
   ar[i] = toll(x);
   }
   F(0 , 0);
   if(sol)
   cout<<sol<<"\n";
   else
   cout<<"Strong\n";
  return 0;
}

