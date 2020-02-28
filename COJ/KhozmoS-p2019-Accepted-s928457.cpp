#include<bits/stdc++.h>

using namespace std;
  string menor (string cads)
  {
      sort(cads.begin(),cads.end());
      return cads;
  }
  int to_numb(string a)
  {
      int sol = 0;
      int ta = a.size();

      int m = pow(10 , ta - 1);
      for(int i = 0 ; i < ta ; i++)
      {
           sol += (a[i] - '0') * m;
           m /= 10;
      }
      return sol;
  }
  bool is_prime(int x)
  {
      if(x == 0)
      return false;
      if(x == 1)
      return false;
      if(x == 2)
      return true;
      if(x % 2 == 0)
      return false;
      for(int  i = 3 ; i * i <= x ; i += 2)
      if(x % i == 0)
      return false;
      return true;
  }
  string cad;
int main()
{

  //cout<<to_numb("1234");
   cin>>cad;
   int sol = 0;
   cad = menor(cad);
   do{

     if(is_prime(to_numb(cad)))
     sol++;
   }while(next_permutation(cad.begin() , cad.end()));
   cout<<sol<<"\n";
    return 0;
}
