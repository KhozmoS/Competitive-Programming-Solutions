#include <bits/stdc++.h>

using namespace std;
int q , a , b;
int n , x;
char v[] = {'P' , 'E' , 'R'};
int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0);
  cin>>n;

  while(n--){
  string cad;
  cin>>cad;
  sort(cad.begin() , cad.end());

  do{
    cout<<cad<<"\n";
  }while(next_permutation(cad.begin() , cad.end()));
  }




    return 0;
}
