#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll k;

string to_bin(ll x)
{
    string res = "";
    if(!x) return "0";

    while(x)
    {
        res = char(x % 2 + 48) + res;
        x >>= 1;
    }

    return res;

}
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>k;
	if(k == 1){
       cout<<2<<" "<<1<<"\n";
       cout<<1<<" "<<2<<"\n";
       cout<<1<<" "<<2<<"\n";
       return 0;
	}

    string cod = to_bin(k);
    reverse(cod.begin() , cod.end());
    int Mpot =cod.size() -1, mpot = 0;
    while(cod[mpot] != '1')
        mpot++;
    int cpi = 0;
    int i = mpot + 1;
    while(i < Mpot)
        cpi += (cod[i++] == '1' ? 1 : 0);

    int N = Mpot + 1 + (Mpot - mpot - 1);
    int M = (Mpot << 1) + (Mpot - mpot) + cpi;


    if(Mpot == mpot) {

      cout<<Mpot+1<<" "<<Mpot*2<<"\n";
      cout<<1<<" "<<Mpot+1<<"\n";
         int in = 1; int fn = 2;int pot[65];
    int j = 0;
    for(i = 1 ; i <= Mpot - 1; i++)
    {
        pot[j++] = in;
        cout<<in<<" "<<fn<<"\n";
        cout<<in++<<" "<<fn++<<"\n";
    }
    pot[j] = in;
    cout<<in<<" "<<Mpot+1<<"\n";
    cout<<in<<" "<<Mpot+1<<"\n";
    return 0;
    }




    if(mpot + 1 == Mpot){cout<<N<<" "<<M<<"\n";}
    else
    cout<<N<<" "<<M<<"\n";

    cout<<1<<" "<<N<<"\n";

    int in = 1; int fn = 2;int pot[65];
    int j = 0;
    for(i = 1 ; i <= Mpot - 1; i++)
    {
        pot[j++] = in;
        cout<<in<<" "<<fn<<"\n";
        cout<<in++<<" "<<fn++<<"\n";
    }
    pot[j] = in;
    cout<<in<<" "<<N<<"\n";
    cout<<in<<" "<<N<<"\n";
    if(mpot + 1 == Mpot){cout<<in<<" "<<N<<"\n"; return 0;}
    in++;

    int lvl[65]; i = mpot + 1; int cantl = Mpot - (mpot + 1);
    while(i < Mpot)
        lvl[i++] = in , in++;



    for(i = mpot + 1 ; i < Mpot - 1; i++){
        cout<<lvl[i]<<" "<<lvl[i + 1]<<"\n";
   
}
if(lvl[i] == 0)while(true);
        cout<<lvl[i]<<" "<<N<<"\n";

    for(i = 0 ; i < Mpot -1; i++)
       if(cod[i] == '1')
          cout<<pot[i]<<" "<<lvl[i + 1]<<"\n";

      if(cod[Mpot - 1] == '1') cout<<pot[Mpot - 1]<<" "<<N<<"\n";
}
