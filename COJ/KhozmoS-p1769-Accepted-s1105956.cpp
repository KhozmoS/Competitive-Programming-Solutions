#include<bits/stdc++.h>


using namespace std;

const int MAX = 1e5 + 5;
char s[MAX];
int a[30] , b[30];


int main()
{

    //ios_base::sync_with_stdio(0);cin.tie(0);
    scanf("%s" , s);
    int t = strlen(s);
    for(int i = 0 ; i < t ; i++) a[s[i] - 'a']++;
    scanf("%s" , s);
    t = strlen(s);
    for(int i = 0 ; i < t ; i++) b[s[i] - 'a']++;

    bool ans = false;

    for(int i = 0 ; i < 30 ; i++)
       if(a[i] && b[i])
          ans = true;
       else if(a[i] && !b[i])
       {
           ans = false;
           break;
       }
     if(ans) {cout<<"YES\n";   return 0;}
    for(int i = 0 ; i < 30 ; i++)
       if(a[i] && b[i])
          ans = true;
       else if(!a[i] && b[i])
       {
           ans = false;
           break;
       }

    cout<<(ans ? "YES\n" : "NO\n");
}
