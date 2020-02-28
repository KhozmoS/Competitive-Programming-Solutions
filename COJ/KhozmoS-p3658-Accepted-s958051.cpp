#include <bits/stdc++.h>

using namespace std;

int a[3], b[3];

int main()
{
    cin >> a[0] >> a[1] >> a[2];
    cin >> b[0] >> b[1] >> b[2];

    sort(a, a + 3);
    sort(b, b + 3);

    bool flag = false;
    for(int i = 0; i < 3; i++)
        if(a[i] != b[i]){
            flag = true;
            break;
        }
    if(!flag){
        if(a[2] * a[2] == a[1] * a[1] + a[0] * a[0])
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    else
        cout << "NO\n";

    return 0;
}
