#include <bits/stdc++.h>

using namespace std;
const int MAX = 1005;

int num[MAX] , nu , de;
int mk[MAX];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);


    while(cin>>nu>>de){
    memset(mk , 0 , sizeof(mk));
    memset(num , 0 , sizeof(num));
    num[0] = nu / de;
    int res = nu % de;

    mk[res] = 1;
    int cur = 1;
    bool flag = false;
    int i = 1;
    int in_c = -1;
    int cont = 0;
    int end_c = -1;
    while(true)
    {
        int x = (res*10) / de;
        vector <int> v;
        v.clear();
        if(!x) v.push_back(0);
        while(x)
        {
            v.push_back(x%10);
            x /= 10;
        }

        //cout<<v.size()<<"\n";
        for(int j = v.size()-1 ; j >= 0 ; j--)
        {
          //  cout<<cur<<" "<<v[j]<<"\n";
            num[cur++] = v[j];
            i++;
        }
        res = (res*10) % de;
        if(mk[res])
        {
            flag = true;
            in_c = mk[res];
            end_c = cur;
            break;
        }

        mk[res] = cur - v.size() + 1;
    }
            cout<<end_c - in_c<<" ";
            cout<<num[0]<<".";
            for(int j = 1 ; j < min(in_c , 51) ; j++){
                cout<<num[j];
            }
              if(in_c <= 50)
                cout<<"(";


            for(int j = min(51 , in_c) ; j <= min(50 , end_c - 1) ; j++){
                cout<<num[j];
            }

            if(in_c <= 50 && end_c > 51)
            cout<<"...)";
            else if(end_c <= 51)
                cout<<")";

            cout<<"\n";
          //cout<<cont<<"\n";
    }
}
