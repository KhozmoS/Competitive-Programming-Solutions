#include<bits/stdc++.h>


using namespace std;

string cad; int N; int sum , ld;
string to_strin(int x)
{
    string ret = "";

    int cont = 0;
    do
    {
        int add = x % 10;
        x /= 10;
        ret = char(add + 48) + ret;
        cont++;
    }while(x != 0 && cont < 4);
    return ret;

}
 int emp1(int x)
 {
     if(x < 1000)
     x += 1000;
     return x;
 }
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>N;
   // cout<<to_strin(11000);
    while(N--)
    {
        cin>>cad;
        for(int i = 0 ; i < cad.size() ; i++)
        sum += (cad[i] - '0');
        string s = cad.substr(10 , 12);
       // cout<<s<<" soy s\n";
        ld = ((s[0] - '0') * 100) + ((s[1] - '0') * 10) + (s[2] - '0');
       // cout<<ld<<" soy ld\n";
        ld *= 10;
        int sol = sum + ld;
        if(sol > 9999){
        string a = to_strin(sol);
        cout<<a<<"\n";
        }
         else{
        sol = emp1(sol);
        cout<<sol<<"\n";
         }
        sum = 0;
        ld = 0;
    }
    return 0;
}
