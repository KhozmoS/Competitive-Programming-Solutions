#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);

     string n;
     cin>>n;
     int sum = 0;
     for(int i = 0 ; i < n.size() ; i++) sum += (n[i] - '0');

     sort(n.begin() , n.end());

     reverse(n.begin() , n.end());

     if(sum % 3 == 0) cout<<n<<"\n";

     else cout<<"-1\n";

    return 0;
}
