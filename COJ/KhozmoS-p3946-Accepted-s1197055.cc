#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int N;string cad;cin>>N>>cad;
    cad = " " + cad;
    int first = 0;
    //first
    for(int i = 1 ; i <= min(N / 3 + 1 , N) ; i++)
        if(cad[i] == 'a' || cad[i] == 'e' || cad[i] == 'o' || cad[i] == 'i' || cad[i] == 'u') first++;
        cout<<first<<" ";
    int second = 0;
    //second
    int top = N / 3 + 1;

    for(int i = top+1 ; i <= min(N , 2*N/3+2) ; i++)
        if(cad[i] == 'a' || cad[i] == 'e' || cad[i] == 'o' || cad[i] == 'i' || cad[i] == 'u') second++;
    cout<<second<<" ";
    //third
    int third = 0;
    for(int i = 2*N/3+3 ; i <= N ; i++)
        if(cad[i] == 'a' || cad[i] == 'e' || cad[i] == 'o' || cad[i] == 'i' || cad[i] == 'u') third++;
    cout<<third<<"\n";

}
