#include <bits/stdc++.h>

using namespace std;

static bool palindrome(string cad){
    string rev = cad;
    reverse(cad.begin() , cad.end());
    if(rev == cad){
       return true;
    }else{
       return false;
    }
}

static bool near_palindrome(string cad){
    string aux = "";
    for(int i = 0; i < cad.size(); i++){
        aux = "";
        for(int j = 0; j < cad.size(); j++){
            if(i != j) aux += cad[j];
        }
        if(palindrome(aux)) return true;
    }
    return false;
}

int main()
{

   ios_base::sync_with_stdio(0);cin.tie(0);

   int n; cin>>n;
   string cad;
   bool flag;
   int i = 0;

   while(n--){
         cin>>cad;
         flag = false;
         if(palindrome(cad)){
            cout<<"Case #"<<(i + 1)<<": palindrome\n";

         }
         else if(!flag && near_palindrome(cad)){
            cout<<"Case #"<<(i + 1)<<": near-palindrome\n";
         }
         else cout<<"Case #"<<(i + 1)<<": neither\n";
         i++;
   }

   return 0;
}
