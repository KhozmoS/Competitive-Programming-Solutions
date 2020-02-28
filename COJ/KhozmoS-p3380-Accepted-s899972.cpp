#include<bits/stdc++.h>
//joel.KhozmoS
int cont;
bool flag;
using namespace std;
string a , b;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        cin>>a>>b;
        int ta = a.size();
        int tb = b.size();
        if(ta != tb){
            cout<<"NO\n";
            continue;
        }
        else{
          for(int i = 0 ; i < ta ; i++){
             if(a[i] == b[i]){
                if(a[ta - i - 1] == b[ta - i - 1])
                    flag = true;
             }

             else if(a[i] == b[ta - i - 1])
             {
                 if(a[ta - i - 1] == b[i])
                    flag = true;
             }
             else
             {
                 flag = false;
                 break;
             }
          }
            }
            if(!flag)
                cout<<"NO\n";
            else
                cout<<"YES\n";
    }
    return 0;
}
