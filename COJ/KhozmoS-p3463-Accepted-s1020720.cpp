#include<bits/stdc++.h>


using namespace std;
const int MAXN = 1111111;

int n , t , cont;
string sol;



struct trio{
 int a , b, c;
 trio(){}
 trio(int a , int b , int c):a(a) , b(b) , c(c){}
  bool operator < (const trio &X) const {
   if(a + b + c < X.a + X.b + X.c) return 1;

   else if(a + b + c > X.a + X.b + X.c) return 0;

   if(a < X.a) return 1; else if(a > X.a) return 0;

   if(c < X.c) return 1; else return 0;
  }
};
vector <trio> vt;

void generar()
{
    cont = 0;
    for(int i = 1 ; i <= n ; i++)
    for(int j = 1 ; j <= n ; j++){
    for(int k = 1 ; k <= n ; k++)
    {
        if(i * j * k > n) continue;

        if(i * j * k == n)
        {
            trio pus = trio(i , j , k);
            vt.push_back(pus);
            cont++;
        }
    }
     if(i * j > n) continue;
    }
}
int main() {
  ios_base::sync_with_stdio(0);cin.tie(0);
   cin>>t;

   while(t--)
   {
       cin>>n;
       generar();
       sort(vt.begin() , vt.end());
       cout<<cont<<"\n";
       for(int i = 0 ; i < cont ; i++)
       {
           for(int j = 0 ; j < vt[i].a ; j++)
           cout<<'C';
           for(int j = 0 ; j < vt[i].b ; j++)
           cout<<'A';
           for(int j = 0 ; j < vt[i].c ; j++)
           cout<<'T';
           cout<<"\n";
       }
       //cout<<cont<<"\n";
       vt.clear();
   }
 return 0;
}
