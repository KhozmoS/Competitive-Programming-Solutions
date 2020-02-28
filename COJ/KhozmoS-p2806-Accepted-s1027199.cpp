#include <bits/stdc++.h>

using namespace std;
const int MAXN = 500005;

//string num , sol;

int n , k;
string sol;
bool marca[MAXN];
int freq[MAXN];
string cad;

int main()
{
   ios_base::sync_with_stdio(0);cin.tie(0);

   cin>>n>>k;
   k = n - k;

   cin>>cad;

   int pos = 0;
   while(k > 0)
   {
        char c = cad[pos];
        for(int i = pos + 1 ; i <= n - k ; i++)
        {
            if(c < cad[i]){
             c = cad[i];
              pos = i;
            }
        }
        sol = sol + c;
        pos++;
        k--;
   }
   cout<<sol<<"\n";

    return 0;
}
//421451gf
