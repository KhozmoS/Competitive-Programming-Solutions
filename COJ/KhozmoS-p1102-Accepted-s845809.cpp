#include <bits/stdc++.h>

using namespace std;

int main()
{
string N;
while(true)
{

cin>>N;
if(N[0]=='0')
break;
int ta=N.size();
int sp=0;
    for(int i=0;i<ta;(i++)+(i++))
{
     sp=sp+(N[i]-'0');
}
     int si=0;
     for(int i=1;i<ta;(i++)+(i++))
      {
       si=si+(N[i]-'0');
       }
   int rest=sp-si;
     if(rest==0||rest%11==0)
cout<<N<<" "<<"is a multiple of 11."<<endl;
else
cout<<N<<" "<<"is not a multiple of 11."<<endl;
}
return 0;



}