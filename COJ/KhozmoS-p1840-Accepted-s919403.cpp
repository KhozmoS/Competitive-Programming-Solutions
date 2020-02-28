#include<bits/stdc++.h>
#define MAXN 34
using namespace std;
int freq[MAXN];
string cad;
int N;
int main()

{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>N;
    for(int k = 0 ; k < N ; k++)
    {
        cin>>cad;
        int ta = cad.size();
        for(int i = 0 ; i < ta ; i++)
        {
            freq[cad[i] - 'A']++;
        }
        int c = freq[1];
        if(freq['B' - 'A'] == c && freq['R' - 'A'] == c && freq['O' - 'A'] == c && freq['K' - 'A'] == c && freq['E' - 'A'] == c && freq['N' - 'A'] == c)
        cout<<"No Secure\n";
        else
        cout<<"Secure\n";
        //LIMPIAR
        for(int i = 0 ; i < MAXN ; i++)
        freq[i] = 0;
    }

    return 0;
}
