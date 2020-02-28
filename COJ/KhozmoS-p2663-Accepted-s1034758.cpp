#include <bits/stdc++.h>

using namespace std;

vector <string> ar[15];
int cont;

void crear()
{
   for(int i = 0 ; i < 10 ; i ++){
   string p = "";
   p += char(i + 48);
   //cout<<p<<"\n";
   ar[i].push_back(p);
   }
   for(int i = 8 ; i > 0 ; i--)
   {
       int pos = i + 1;
       while(pos < 10)
       {
         for(int j = 0 ; j < ar[pos].size() ; j++)
         ar[i].push_back(ar[i][0] + ar[pos][j]);

         pos++;
       }
   }
}
int to_numb(string x)
{
    int y = 0;
    for(int i = 0 ; i < x.size() ; i++)
    y = (y * 10) + (x[i] - '0');

    return y;
}
int main()
{
    //cout<<to_numb("123456789");
   ios_base::sync_with_stdio(0);cin.tie(0);
   crear();
 //  cout<<1000000000<<" "<<123456789<<"\n";
   int t;
   cin>>t;
   while(t--)
   {
       int may = 0 ; int men = 0;
       int a , b;
       cin>>a>>b;
       if(a > b) swap(a , b);

       for(int i = 0 ; i < 10 ; i++)
       for(int j = 0 ; j < ar[i].size() ; j++){
       if(to_numb(ar[i][j]) < a)
       men++;
       if(to_numb(ar[i][j]) <= b)
       may++;
       }
       cout<<may - men<<"\n";
   }

    return 0;
}
