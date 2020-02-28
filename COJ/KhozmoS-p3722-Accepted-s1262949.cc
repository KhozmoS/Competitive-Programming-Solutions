#include <bits/stdc++.h>

using namespace std;

int mx[] = {0 , 1, 1, 1, 0 , -1, -1 , -1};
int my[] = {1 , 1, 0, -1, -1 , -1, 0 , 1};

char M[1005][1005];
char mi[1005][1005];


int main()
{
    //ios_base::sync_with_stdio(0);cin.tie(0);

    int n;while(cin>>n && n){
    vector <int> s(n+2,0);
    for(int x = 1 ; x <= 100 ; x++) {
    for(int i = 0 ; i < n ; i++)
            s[i] = i+1;

    int cur = 0;int ans = 0;int flag = false;
    while(s[0])
    {

        int it = x;
        if(flag)
        while(it!=1)
        {
            cur++;
            if(!s[cur])
                cur = 0;
            it--;
        }
        flag = true;

        ans = s[cur];
        int i  = cur;
        if(!s[cur+1]) cur = 0;
        while(s[i])
        {
            s[i] = s[i+1];
            i++;
        }

    }
    if(ans == 13)
    {
        cout<<x<<"\n";
        break;
    }
    }
    }
}
