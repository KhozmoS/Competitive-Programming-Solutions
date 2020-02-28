#include <bits/stdc++.h>

using namespace std;

//bool mk[MAXN]

bool is_prime(int x)
{
  if(x == 0 || x == 1)
        return false;
  if(x == 2)
     return true;
  if(x % 2 == 0)
     return false;
  for(int i = 3 ; i * i <= x ; i += 2)
    if(x % i == 0)
    return false;

  return true;
}
int to_num(string cad)
{
    int ta = cad.size();
    int mult = pow(10 , ta);
    int num = 0;
    for(int i = 0 ; i < ta ; i++)
    {
        num = num + ((cad[i] - '0') * mult);
        mult /= 10;
    }
    return num / 10;
}
bool f1 , f2;

int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
 //cout<<to_num("41242");
    string n;
    cin>>n;
     sort(n.begin() , n.end());
        do{
          if(is_prime(to_num(n)))
           f1 = true;
          if(to_num(n) % 6 == 0)
           f2 = true;

        }while(next_permutation(n.begin() , n.end()));
        if(f1 && f2){
         cout<<"Both\n";   
        return 0;
        }
        if(f1){
         cout<<"Prime\n";
         return 0;
        }
        if(f2){
         cout<<"Divisible by 6\n";
         return 0;
        }
          
        cout<<"Neither\n";
    return 0;
}
