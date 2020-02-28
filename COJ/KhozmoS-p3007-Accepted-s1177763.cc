#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e6 + 5;
const int mod = 1e9 + 7;
typedef unsigned long long ll;

long long K[MAX];

char arr[1000][1000];
bool check(int x , int y)
{
    int cnt = 0;
    //up
    for(int i = x-1 ; i > 0 ; i--)
        if(arr[i][y] == '*') cnt++;
    //down
    for(int i = x+1 ; i <= 8 ; i++)
        if(arr[i][y] == '*') cnt++;
    //left
    for(int i = y-1 ; i > 0 ; i--)
        if(arr[x][i] == '*') cnt++;
    //right
    for(int i = y+1 ; i <= 8 ; i++)
        if(arr[x][i] == '*') cnt++;
    //diago1
    int i , j;
    for(i = x-1 , j = y-1 ; i > 0&&j>0 ; i-- , j--)
            if(arr[i][j] == '*') cnt++;

    for(i = x-1 , j = y+1 ; i > 0&&j<9 ; i-- , j++)
            if(arr[i][j] == '*') cnt++;

    for(i = x+1 , j = y+1 ; i < 9&&j<9 ; i++ , j++)
            if(arr[i][j] == '*') cnt++;

    for(i = x+1 , j = y-1 ; i <9&&j>0 ; i++ , j--)
            if(arr[i][j] == '*') cnt++;

    return (cnt==0);
}

int main()
{
    //cout<<(12 & 1)<<"\n";
    //ios_base::sync_with_stdio(0);cin.tie(0);
    int cnt = 0;
    for(int i = 1; i <= 8 ; i++)
        for(int j = 1; j <= 8 ; j++)
           cin>>arr[i][j];
    for(int i = 1; i <= 8 ; i++)
        for(int j = 1; j <= 8 ; j++)
        {
            if(arr[i][j] == '*')cnt++;
            if(arr[i][j] == '*' && !check(i , j))
            {
                cout<<"invalid\n";
                return 0;
            }
        }
     if(cnt == 8)   
          cout<<"valid\n";
        else
          cout<<"invalid\n";        
}
