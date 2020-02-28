#include <bits/stdc++.h>

using namespace std;

stack <int> p;
queue <int> c;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;

    while(cin>>n && n){
    while(!c.empty())c.pop();
    while(!p.empty())p.pop();
    bool ok = true;
    while(n--){
        int x;cin>>x;
        c.push(x);
    }
    int last = 0;
    while(!c.empty() || !p.empty())
    {
        if(!p.empty())
        {
            int x = p.top();
            if(x == last+1)
            {
                last = x;
                p.pop();
                continue;
            }
        }
        if(!c.empty())
        {
            int x = c.front();
            if(x == last+1)
            {
                last = x;
                c.pop();
                continue;
            }
            p.push(c.front());
            c.pop();
            continue;
        }
        cout<<"no\n";
        ok = false;
        break;
    }
    if(ok)
        cout<<"yes\n";
    }
}
