//1279 - Fermat's Christmas GREATSHIT!!
//by KhozmoS

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int MAX = 1e3+5;
int M[MAX][27];
int cursors[27];
string alph = "A B C D E F G H I J K L M N O P Q R S T U V W X Y Z\n";
int main()
{
   ios_base::sync_with_stdio(0);cin.tie(0);
    int mini = 0;
    for(int i = 0 ; i < 26 ; i++)
        cursors[i] = 500;
    string cad;
    while(cin>>cad)
    {
        for(int i = 0 ; i < cad.size() ; i++)
        {
           int id = cad[i] - 'A';
           if(id < 0 || id > 25) continue;
           int cur = cursors[id];
           M[cur][id]++;
           cursors[id]--;
           mini = max(mini , 500 - cur);
        }

    }
//    cout<<mini;

    for(int i = 500 - mini; i <= 500 ; i++)
        for(int j = 0 ; j < 26 ; j++)
           cout<<(M[i][j] ? '*' : ' ')<<(j == 25 ? '\n' : ' ');
    cout<<alph;
}
