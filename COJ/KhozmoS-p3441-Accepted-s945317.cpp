#include <bits/stdc++.h>

using namespace std;
int n;
int t , cont = 1;
int main()
{   scanf("%d",&t);
     for(int i = 0; i < t; i++){
       scanf("%d",&n);
        int sol = log2(n);
        cout<<"Case #"<<cont<<": "<<sol<<"\n";
        cont++;
        }
    return 0;
}
