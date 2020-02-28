#include <bits/stdc++.h>

using namespace std;


typedef long long ll;
int n;
const int MAXN = 27;


bool mk[MAXN];
int sud[MAXN][MAXN];




int main()
{
   ios_base::sync_with_stdio(0);cin.tie(0);



    int t;
    cin>>t;

    while(t--)
    {

      memset(mk , false , sizeof(mk));
      int n;
      cin>>n;

      for(int i = 1 ; i <= n ; i++)
       for(int j = 1 ; j <= n ; j++)
        cin>>sud[i][j];

        bool flag = false;

      for(int i = 1 ; i <= n ; i++){
       for(int j = 1 ; j <= n ; j++)
       {
           if(!mk[sud[i][j]]){
           mk[sud[i][j]] = true;
           }
           else
            flag = true;
       }
       memset(mk , false , sizeof(mk));
      }
        if(flag)
        {
            cout<<"no\n";
            continue;
        }
        flag = false;
        //memset(mk , false , sizeof(mk));

       for(int i = 1 ; i <= n ; i++){
       for(int j = 1 ; j <= n ; j++)
       {
           if(!mk[sud[j][i]]){
           mk[sud[j][i]] = true;
           }
           else
            flag = true;
       }
       memset(mk , false , sizeof(mk));
       }
       if(flag)
        {
          //  cout<<"wa";
            cout<<"no\n";
            continue;
        }


       for(int i = 1 ; i + sqrt(n) < n ; i += sqrt(n)){
        for(int j = 1 ; j + sqrt(n) < n ; j += sqrt(n))
         {
             memset(mk , false , sizeof(mk));

            for(int k = i ; k < (i + sqrt(n)) ; k++)
             for(int l = j ; l < (j + sqrt(n)) ; l++)
               mk[sud[k][l]] = true;

            for(int k = 1 ; k <= n ; k++)
            {
              if(!mk[k])
               goto END;
            }

         }
       }

         cout<<"yes\n";
         continue;
        END:
            cout<<"no\n";
    }



    return 0;
}
