#include <bits/stdc++.h>

using namespace std;

map <string , int> pos;

int freq[10] , n , t;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    pos["TTT"] = 0;
    pos["TTH"] = 1;
    pos["THT"] = 2;
    pos["THH"] = 3;
    pos["HTT"] = 4;
    pos["HTH"] = 5;
    pos["HHT"] = 6;
    pos["HHH"] = 7;
    cin>>t;string cad;
    while(t--)
    {
        cin>>n;
        cin>>cad;
        for(int i = 0 ; i < cad.size() ; i++){
           freq[pos[cad.substr(i , 3)]]++;
        }
        freq[0] -= 2;
        cout<<n<<" ";
        for(int i = 0 ; i < 8 ; i++)
            cout<<freq[i]<<(i == 7 ? '\n' : ' ') , freq[i] = 0;
    }

    return 0;
}
