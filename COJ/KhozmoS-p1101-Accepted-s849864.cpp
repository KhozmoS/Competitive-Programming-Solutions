#include <bits/stdc++.h>

using namespace std;

bool P[2 * 100000 + 5];

 string to_bin(int a)
 {
        string bin="";
   while(a/2!=0)
   {  if(a%2==1)
      {
      bin="1"+bin;

      }
      else
      {
       bin="0"+bin;

      }
       a=a/2;
   }
   bin="1"+bin;
    return bin;

 }
bool to_pal(string cad)
{
   string cad1=cad;
   reverse(cad1.begin(),cad1.end());
   if(cad==cad1)
   return true;
   else
   return false;
}

int main()
{
    for(int i = 1; i < 2 * 100000 + 2; i++)
        if(to_pal(to_bin(i)))
            P[i] = true;

    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;

        int cont = 0;
        for(int i = a; i <= b; i++)
            if(P[i])
            {
                if(cont == 0)
                    cout << i;
                else
                    cout << " " << i;
                cont++;
            }

        cout << endl;
    }




    return 0;
}
