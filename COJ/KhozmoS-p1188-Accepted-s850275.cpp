#include <bits/stdc++.h>

using namespace std;

int main()
{
     string A,B;
    cin>>A;
    cin>>B;
    int tb=B.size();
    int ta=A.size();
    int mult=0;
    int s=0;
     for(int i=0;i<tb;++i)
     {
       for(int e=0;e<ta;++e)
       {
         mult=(A[e]-'0')*(B[i]-'0');
         s+=mult;
         mult=0;
       }
     }
     cout<<s<<endl;

    return 0;
}
