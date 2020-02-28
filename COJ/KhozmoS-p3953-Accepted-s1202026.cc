#include <iostream>

using namespace std;
bool mk[305];
int main()
{
   int k;cin>>k;
   string a;cin>>a;int cnt = 0;
   int in = -1;
   for(int i = 0 ; i < a.size() ; i++)
   {
       char c = a[i];
       if(!mk[c]) cnt++;
       mk[c] = true;
       if(cnt == k && in == -1) in = i;
   }
   if(in == -1)cout<<"NO\n";
   else{
        cout<<"YES\n";
        for(int i = in ; i < a.size() ; i++) cout<<a[i];cout<<"\n";
   }
}
