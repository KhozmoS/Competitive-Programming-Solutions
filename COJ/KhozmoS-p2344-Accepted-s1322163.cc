#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e6;


struct Country {
    string name;
    int gold, silver, bronze;
    Country ( string name0, int gold0, int silver0, int bronze0 ) {
        name = name0;
        gold = gold0;
        silver = silver0;
        bronze = bronze0;
    }
    Country(){
        name = "";
        gold = 0;
        silver = 0;
        bronze = 0;
    }

} World[MAX];


bool cmp( Country A , Country B )
{
    if( B.gold == A.gold )
            if( B.silver == A.silver ) {
                if( B.bronze == A.bronze )
                    return B.name < A.name;
                else
                    return B.bronze > A.bronze;
            }
            else return B.silver > A.silver;
        else return B.gold > A.gold;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int idx = 1;
    while( true ) {
        string name;
        int gold , silver , bronze;
        cin>>name;
        if( name == "@" ) {
            idx--;
            for( int i = 1 ; i <= idx ; i++)
                for( int j = i ; j <= idx ; j++ )
                    if( cmp( World[i] , World[j] ) )
                        swap( World[i], World[j] );

            for( int i = 1 ; i <= idx ; i++ )
                cout<<World[i].name<<"\n";
            cout<<name<<"\n";
            idx = 1;
            // CLEAN
            for( int i = 1 ; i <= 100 ; i++ )
                World[i] = Country( );
            continue;
        }
        if( name == "#" ) {
            idx--;
            for( int i = 1 ; i <= idx ; i++)
                for( int j = i ; j <= idx ; j++ )
                    if( cmp( World[i] , World[j] ) )
                        swap( World[i], World[j] );

            for( int i = 1 ; i <= idx ; i++ )
                cout<<World[i].name<<"\n";
            return 0;
        }
        cin>>gold>>silver>>bronze;
        World[idx] = Country( name , gold, silver , bronze );
        idx++;
    }
}
