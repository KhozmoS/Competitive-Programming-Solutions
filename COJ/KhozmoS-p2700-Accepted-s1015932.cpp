#include<bits/stdc++.h>

using namespace std;

string cad1;
string cad2;

string first , second , firstysecond;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>cad1>>cad2;
    for(int i = 0 ; i < cad1.size() ; i++){
     bool flag = false;
    for(int j = 0 ; j < cad2.size() ; j++)
    {
        if(cad1[i] == cad2[j])
        flag = true;
    }
      if(flag)
      firstysecond += cad1[i];
      else
      first += cad1[i];
    }
     for(int j = 0 ; j < cad2.size() ; j++)
     {
       bool flag = false;
       for(int i = 0 ; i < cad1.size() ; i++)
       {
           if(cad2[j] == cad1[i])
           flag = true;
       }
        if(!flag)
        second += cad2[j];
     }
     cout<<"First:"<<first<<"\n";
     cout<<"Second:"<<second<<"\n";
     cout<<"First&Second:"<<firstysecond<<"\n";
    return 0;
}
/*100 100
  100 100
  100 100
  100 100
  100 100
  100 100
  100 100
  100 100
  100 100
  100 100*/
