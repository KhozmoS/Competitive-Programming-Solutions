#include <bits/stdc++.h>

using namespace std;
const int MAXN = 1111111;

 map <string , int> m;

/*struct trio{
string a , b , c;
trio(){}
trio(string a , string b , string c):a(a), b(b) , c(c){}
};*/

string ar[4];
int bes;

int main() {

 ios_base::sync_with_stdio(0);cin.tie(0);
   //ar[0] = "1"; ar[1] = "2"; ar[2] = "3";

  int n; cin>>n;
  while(n--){
  string peg = "";
  cin>>ar[0]>>ar[1]>>ar[2];
  do{
     peg = ar[0] + " " + ar[1] + " " + ar[2];

     m[peg]++;
    }while(next_permutation(ar , ar + 3));

    if(bes < m[peg]) bes = m[peg];
  }
   cout<<bes<<"\n";
	return 0;
}
