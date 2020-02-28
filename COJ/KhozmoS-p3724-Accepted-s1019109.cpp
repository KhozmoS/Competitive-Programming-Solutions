#include <iostream>

using namespace std;

string hora;

string num(string a)
{
    bool flag = true;

    int n = 0;

    n += (a[0] - '0') * 10;
    n += (a[1] - '0');
    n += 12;
    //cout<<n<<"\n";
        int t = n % 10;
        string ret = "";
        ret += char(t + 48);
        n /= 10;
        ret = char(n + 48) + ret;
        return ret;


}

int main()
{
    cin>>hora;

    if(hora[8] == 'P')
    {
        string comp = "12";
        if(hora[0] == comp[0] && hora[1] == comp[1]){
        cout<<"12";
        for(int i = 2 ; i < 8 ; i++)
        cout<<hora[i];
        }else{
        string ver = "";
       ver = hora[1]; ver = hora[0] + ver;
      cout<<num(ver);
      for(int i = 2 ; i < 8 ; i++)
      cout<<hora[i];
        }
      cout<<"\n";
    }
    else
    {
        string comp = "12";
        if(hora[0] == comp[0] && hora[1] == comp[1]){
        cout<<"00";
        for(int i = 2 ; i < 8 ; i++)
        cout<<hora[i];
        }
        else
        for(int i = 0 ; i < 8 ; i++)
        cout<<hora[i];

        cout<<"\n";

    }
    return 0;
}
