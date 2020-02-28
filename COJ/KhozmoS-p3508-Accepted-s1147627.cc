#include <bits/stdc++.h>

using namespace std;

int  t;

int main()
{
    cin>>t;
    for(int cas = 1 ; t-- ; cas++)
    {
        int n , k , col[1000] , box[1000];
        cin>>n;
        for(int i = 0 ; i < n ; i++) cin>>col[i];
        cin>>k;
        
        for(int i = 0 ; i < k ; i++) cin>>box[i];
        sort(col , col + n);
        sort(box , box + k);
        reverse(box , box + k);
        reverse(col , col + n);
        if(n > k) {
            cout<<"Case #"<<cas<<": no\n";
            continue;
        }
        bool ans = true;
        for(int i = 0 ; i < n ; i++)
        {
            if(col[i] > box[i])
            {
                ans = false;
                break;
            }
        }
        if(!ans)
            cout<<"Case #"<<cas<<": no\n";
        else
            cout<<"Case #"<<cas<<": yes\n";
    }
    return 0;
}
