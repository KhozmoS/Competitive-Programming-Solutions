#include <bits/stdc++.h>

using namespace std;
const int MAXN = 11111111;
int n;


bool mark[MAXN];
string cad;

int main()
{
    //cout << "Hello world!" << endl;
      ios_base::sync_with_stdio(0);cin.tie(0);
      cin>>n;
     //cout<<'i' - '0';
     while(n -- ){
    cin>>cad;
      int ta = cad.size();
     for(int i = 0 ; i < ta ; i++)
      {

        if(cad[i] - '0' > -1 && cad[i] - '0' < 10)
        {
          mark[cad[i] - '0']  = true;
        }

        else if(cad[i] - 'a' > -1 && cad[i] - 'a' < 28)
          mark[cad[i] - 'a' + 10] = true;

        else
          mark[cad[i] - 'A' + 40] = true;

    }
      int sol = 0;
         for(int i = 0 ; i < 100 ; i++)
          if(mark[i]) sol++;

          cout<<sol<<"\n";
          //LIMPIAR
          for(int i = 0 ; i < 100 ; i++) mark[i] = false;
}
    return 0;
}
