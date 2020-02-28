#include <bits/stdc++.h>

using namespace std;
//map <string , bool> m;
typedef long long LL;


//LL n , m;
int sol[7];
int main()
{
    //ios_base::sync_with_stdio(0);cin.tie(0);
    char c;
    
    while(cin>>c)
    {
        //if(c == '\n') break;
        c = tolower(c);
        if(c == 'a') sol[0]++;
        if(c == 'e') sol[1]++;
        if(c == 'i') sol[2]++;
        if(c == 'o') sol[3]++;
        if(c == 'u') sol[4]++;
    }
    for(int i = 0 ; i < 5 ; i++) cout<<sol[i]<<" ";
    return 0;
}
