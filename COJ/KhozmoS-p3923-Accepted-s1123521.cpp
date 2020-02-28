#include <bits/stdc++.h>

using namespace std;
const int MAX = 1e5+5;
int ar[MAX];
vector <string> RI;
vector <string> DRI;
vector <string> DI;

int n , k;
int cant[MAX];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cant[2] = 1;
    cant[3] = 3;
    int j = 4;
    do{

        cant[j] = cant[j - 1] + cant[j - 2] + 1;
    }while(cant[j++] < MAX);

    cin>>n>>k;
    bool mon = false;
    bool flag = false;
    int cont = 0;
    for(int i = 0 ; i < k ; i++)
            cin>>ar[i];

    for(int i = 0 ; i < k ; i++){
            if(i == 1)
            {
                if(ar[i - 1] < ar[i])
                  mon = true;
                else if(ar[i - 1] > ar[i])
                  mon = false;
                else
                    flag = true;

                if(abs(ar[i] - ar[i - 1]) > 2)
                        flag = true;
            }
            if(i)
            {
            if(ar[i - 1] == 2 && ar[i] == 1)
                    flag = true;
            if(ar[i - 1] == 1 && ar[i] == 2)
              flag = true;

                if(ar[i] == ar[i - 1])
                    flag = true;
                if(mon && ar[i - 1] > ar[i])
                {
                    cont++;
                    mon = false;
                }
                else if(!mon && ar[i - 1] < ar[i]){
                    cont += 3;
                    mon = true;
                }

                if(abs(ar[i] - ar[i - 1]) > 2)
                    flag = true;
               // cout<<"wa\n";
              // cout<<ar[i - 1]<<" "<<ar[i + 1]<<"\n";
                if(ar[i - 1] == ar[i + 1]){
                    flag = true;

                }


            }
    }
    if(flag || cont > 1) cout<<"N\n";

    else cout<<"S\n";


    return 0;
}
