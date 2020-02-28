#include<bits/stdc++.h>

using namespace std;
  int id,dia,mes,anno,N;
  int uno,dos,tres,cuatro,cinco,seis,siete,ocho,nueve,diez,once,doce;
int main ()
{
    scanf("%d", &N);
    string a;
    //scanf("%d %d/%d/%d/", &id, &dia, &mes, &ano);
     for(int i = 0; i < N; i++)
     {
         scanf("%d %d/%d/%d", &id, &dia, &mes, &anno);
         if(mes == 1)
            uno++;
         else if(mes == 2)
            dos++;
         else if(mes == 3)
            tres++;
         else if(mes == 4)
            cuatro++;
         else if(mes == 5)
            cinco++;
         else if(mes == 6)
            seis++;
         else if(mes == 7)
            siete++;
         else if(mes == 8)
            ocho++;
         else if(mes == 9)
            nueve++;
         else if(mes == 10)
            diez++;
         else if(mes == 11)
            once++;
         else if(mes == 12)
            doce++;
     }
        cout<<"1 "<<uno<<endl;
        cout<<"2 "<<dos<<endl;
        cout<<"3 "<<tres<<endl;
        cout<<"4 "<<cuatro<<endl;
        cout<<"5 "<<cinco<<endl;
        cout<<"6 "<<seis<<endl;
        cout<<"7 "<<siete<<endl;
        cout<<"8 "<<ocho<<endl;
        cout<<"9 "<<nueve<<endl;
        cout<<"10 "<<diez<<endl;
        cout<<"11 "<<once<<endl;
        cout<<"12 "<<doce<<endl;
    return 0;
}
