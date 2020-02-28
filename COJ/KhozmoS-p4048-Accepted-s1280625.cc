#include <bits/stdc++.h>

using namespace std;


int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
    cin>>t;
    string cad;
    while(t--)
    {
        int n;cin>>n;
        cin>>cad;
        int left = 0;
        int right = 0;
        int cntl = 0;
        int cntr = 0;
        for(int i = 0; i < n ; i++)
        {
            if(cad[i] == '<'){
                left++;
                cntl += right;
            }
            else right++;
        }
        cout<<cntl<<"\n";
    }
}
