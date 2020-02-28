#include <iostream>

using namespace std;
long long q , a , b;
char v[] = {'P' , 'E' , 'R'};
int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0);
  string cad;
  cin>>cad;
  int ans = 0;
  for(int i = 0 ; i < cad.size() ; i++)
    if(v[i % 3] != cad[i])
        ans++;

    cout<<ans<<"\n";
    return 0;
}
