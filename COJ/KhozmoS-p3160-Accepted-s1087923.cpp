#include <bits/stdc++.h>

using namespace std;
const int MAX = 1e3 + 5;
int n , dp[MAX][MAX];
bool flag;
string s1 , s2;

void F(string ans , int w , int b , int pos1 , int pos2)
{
    if(pos1 > n || pos2 > n || abs(w - b) > 1 || flag) return;

    if(pos2 == n && pos1 == n)
    {
        cout<<ans<<"\n";
        flag = true;
        return;
    }
    if(dp[pos1][pos2]) return;

    F(ans + '1' , (s1[pos1] == '0' ? w + 1 : w) , (s1[pos1] == '1' ? b + 1 : b) , pos1 + 1 , pos2);
    //dp[pos1 + 1][pos2] = true;
    F(ans + '2' , (s2[pos2] == '0' ? w + 1 : w) , (s2[pos2] == '1' ? b + 1 : b) , pos1 , pos2 + 1);
    dp[pos1][pos2] = true;
}
int main()
{
   ios_base::sync_with_stdio(0);cin.tie(0);

   cin>>n>>s1>>s2;
   F("" , 0 , 0 , 0 , 0);

   return 0;
}
