#include <bits/stdc++.h>

using namespace std;
int a;
 vector <int> V;
int v(int n){
    int x=0;
    while(n>0){
        n/=2;
        x++;
    }
return x-1;
}
int main()
{
    int n;
    int N;
    cin>>N;
    int i = 0;
     for(int j=0;j<N;j++){
    cin>>n; int x;
     while(n!=0){
       x = v(n);
       V.push_back(x);
       n -= pow(2 , x);
        }
        sort(V.begin(),V.end());
        int ta = V.size();
         for(int i = 0 ;i < ta ;i++){
            cout<< V[i]<<" ";
         }
         cout<<endl;
         V.clear();
     }
    return 0;
}
