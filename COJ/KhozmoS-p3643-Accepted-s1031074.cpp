#include <bits/stdc++.h>

using namespace std;
const int MAXN = 1005;

int ar[MAXN];
int freq[111111];
int wa;

void triang()
{

    for(int i = 1 ; i < MAXN ; i++)
    ar[i] = ar[i - 1] + i;

}

int main()
{
    ios_base::sync_with_stdio(0);////
    cin.tie(0);
    triang();

    for(int i = 1 ; i < 100005 ; i++)
    {
     int menor = 11111111;
    for(int j = 1 ; j < MAXN ; j++)
    {
      if(i - ar[j] < 0)
      {
        freq[i] = menor;
        goto END;
      }
      if(freq[i - ar[j]] < menor)
      {
         menor = freq[i - ar[j]] + 1;
      }
      if(freq[i - ar[j]] == 0)
      {
          freq[i] = 1;
          goto END;
      }
    }
    END:
     wa++;
    }
   int n;
     while(cin>>n && n != EOF)
     {
         cout<<freq[n]<<"\n";
     }

  return 0;
}
