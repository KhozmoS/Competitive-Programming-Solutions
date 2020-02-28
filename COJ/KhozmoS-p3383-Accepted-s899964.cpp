#include<bits/stdc++.h>
//N = cantidad de gamse , S = cant de sets pa ganar  ,J = cant de juegos min pa ganar un set
//D = un jugador debe ganar al menos esa cant de de juegos mas q su oponente pa ganar el set
using namespace std;
int N , S , J , D ,cseta , csetb ,pa ,pb;
string game;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>N>>S>>J>>D;
    cin>>game;
    for(int i = 0 ; i < N ; i++)
    {
        if(game[i] == 'A')
            pa++;
        else
            pb++;
        if(pa >= J && pa - pb >= D){
            cseta++;
            pa = 0;
            pb = 0;
        }
        else if(pb >= J && pb - pa >= D){
            csetb++;
            pa = 0;
            pb = 0;
        }
    }
    cout<<cseta<<" "<<csetb<<"\n";
    return 0;
}
