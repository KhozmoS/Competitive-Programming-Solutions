#include <bits/stdc++.h>

using namespace std;
 string bin;
 string a;
long long dec (string cad)
  {
      long long sum = 0;
     reverse(cad.begin(),cad.end());
      for(int i = 0 ; i < cad.size() ; i++)
      {
        if(cad[i] == '1')
            sum += pow(2 , i);
      }

     return sum;
  }
  string oct (long long n)
  {

      while(true){
         a = char(n % 8 + 48) + a;
         n /= 8;
         if(n < 1)
          break;
      }
      return a;
  }
  int ar[55];

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>bin;
    //cout<<bin.substr(0 , 3);
    //cout<<dec("001");
    int cont = 0;

    for(int i = bin.size() - 1 ; i >= 0 ; i -= 3)
    {
        if(i - 2 >= 0)
        {
            string cad = "";
           // cout<<i<<"\n";
           for(int j = i - 2 ; j <= i ; j++)
            cad = cad + bin[j];

          ar[cont] = dec(cad);
          //cout<<bin.substr(i - 2 , i + 1)<<"\n";
         // i -= 2;
          cont++;
        }
        else
        {
            string cad = "";
           for(int j = 0 ; j <= i ; j++)
            cad = cad + bin[j];

          ar[cont] = dec(cad);
          cont++;
          break;
        }
    }
     for(int i = cont - 1 ; i >= 0 ; i--)
        cout<<ar[i];



    return 0;
}
