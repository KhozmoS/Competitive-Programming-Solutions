#include <bits/stdc++.h>

using namespace std;
const int MAXN = 1050000;
typedef long long ll;

//map <string , int> mapa;

string ar;
int n , m;


int cont;

void F(string bin , int c)
{
    if(c == n)
    {
      ar += bin;
      cont += n;
      return;
    }

    F(bin + '1' , c + 1);
    F(bin + '0' , c + 1);

}

bool ver(string a , string b , int tor)
{
    int ja = 0;
    for(int i = 0 ; i < n ; i++)
     if(a[i] == b[i] && a[i] == '1')
     ja++;

    if(ja == tor)
       return true;

       return false;

}

int main()
{

 ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n>>m;
  F("" , 0);
  //cout<<cont / n<<"\n";
      for(int t  = 0 ; t < m ; t++)
      {
          string jug; int tor;

          cin>>jug>>tor;

         //   if(mapa[jug] == tor)
          //      continue;

           // mapa[jug] = tor;

           for(int i = 0 ; i < cont ; i += n)
           {
                   string comp = "";

                 for(int k = i ; k <= (i + n - 1) ; k++)
                  comp += ar[k];

            //          cout<<comp<<"\n";

            if(!ver(jug , comp , tor)){

             for(int j = (n - 1) ; j >= 0 ; j--)
              ar[i + j] = ar[cont - (n - j)];

             cont -= n;
             i -= n;
            }

           }

      }
          // cout<<"\n";

        //for(int i = 0 ; i < cont ; i++)
          //  cout<<ar[i]<<"\n";

        if(cont < 1)
           cout<<"IMPOSSIBLE";
        else if((cont) / n > 1)
           cout<<"NOT UNIQUE";
        else
          for(int i = 0 ; i < cont ; i++)
            cout<<ar[i];

        cout<<"\n";
      //cout<<ar;
    return 0;
}
