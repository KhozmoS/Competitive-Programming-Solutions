#include <bits/stdc++.h>

using namespace std;

int N , B , account[25] , D , C , V , debt[25] , graph[25][25] , mk[25];


int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    while( cin>>B>>N && B)
    {
        memset( account , 0 , sizeof( account ) );        
        bool ok = true;

        for( int i = 1 ; i <= B ; ++i ) cin>>account[i];
        while( N-- )
        {
            cin>>D>>C>>V;            
            account[C] += V;
            account[D] -= V;
        }

        for( int i = 1 ; i <= B ; ++i) {            
            ok &= ( account[i] >= 0 );
        }
        cout<<(ok ? "S" : "N")<<"\n";
    }
}
