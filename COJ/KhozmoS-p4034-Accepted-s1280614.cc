#include <bits/stdc++.h>

using namespace std;

typedef pair <int , int> par;

set <int> one;

set < par > two;

int t , c;
string name;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
    cin>>t;
    for(int i = 1 ; i <= 2*t ; i++)
    {
        if(i&1) two.insert(par(i,i+1));
        one.insert(i);
    }
    int m;cin>>m;
    while(m--)
    {
        int type;
        cin>>type;
        if(type==2)
        {
            cin>>name;
            if(!two.size()) cout<<name<<" left\n";
            else {
                par x = *two.begin();
                cout<<name<<" "<<x.first<<"\n";
                one.erase(x.first);
                one.erase(x.second);
            }
            cin>>name;
            if(!two.size()) cout<<name<<" left\n";
            else {
                par x = *two.begin();
                cout<<name<<" "<<x.second<<"\n";
                two.erase(x);
            }
        }
        else{
            cin>>name;
            if(!one.size()) cout<<name<<" left\n";
            else {
                int x = *one.begin();
                cout<<name<<" "<<x<<"\n";
                one.erase(x);
                if(two.size())
                {
                    par y = *two.begin();
                    if(y.first==x){
                       //cout<<name<<" "<<x<<"\n";
                       two.erase(y);
                    }
                    else if(y.second==x){
                      // cout<<name<<" "<<x<<"\n";
                       two.erase(y);
                    }
                }
            }
        }
    }

}
