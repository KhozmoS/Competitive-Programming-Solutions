#include<bits/stdc++.h>
#define MAXN 105

using namespace std;
int MA1[MAXN][MAXN];
int MA2[MAXN][MAXN];
int R[MAXN][MAXN];
int n1 , m1 , n2 , m2 , sum;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n1>>m1;
    for(int i = 0 ; i < n1 ; i++)
     for(int j = 0 ; j < m1 ; j++)
      cin>>MA1[i][j];
    cin>>n2>>m2;
    for(int i = 0 ; i < n2 ; i++)
     for(int j = 0 ; j < m2 ; j++)
      cin>>MA2[i][j];
      if(m1 != n2)
      cout<<"The matrices can not be multiplied\n";
      else{
       for(int i = 0 ; i < n1 ; i++)
       {for(int j = 0 ; j < m2 ; j++)
         {
               int k = 0; int l = 0;
                while(k < m1 && l < n2)
                {
                   sum += (MA1[i][k] * MA2[l][j]);
                   k++;l++;
                }
              R[i][j] = sum;
              sum = 0;
         }
       }
          for(int i = 0 ; i < n1 ; i++){
           for(int j = 0 ; j < m2 ; j++)
             cout<<R[i][j]<<" ";
             cout<<"\n";
          }
      }

    return 0;
}
