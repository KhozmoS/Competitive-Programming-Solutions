#include <bits/stdc++.h>

using namespace std;

static bool palindrome(string cad){
    string rev = cad;
    reverse(cad.begin() , cad.end());

   return rev == cad;
}

static bool near_palindrome(string cad){
    string aux;
    for(int i = 0; i < cad.size(); i++){
        aux = "";
        for(int j = 0; j < cad.size(); j++)
            if(i != j) aux += cad[j];

        if(palindrome(aux)) return true;
    }
    return false;
}

int main()
{

   ios_base::sync_with_stdio(0);cin.tie(0);

   int n; cin>>n;
   string cad;

   for(int i = 1 ; n-- ; i++){
         cin>>cad;

         if(palindrome(cad)) cout<<"Case #"<<(i)<<": palindrome\n";

         else if(near_palindrome(cad)) cout<<"Case #"<<(i)<<": near-palindrome\n";

         else cout<<"Case #"<<i<<": neither\n";

   }

   return 0;
}
