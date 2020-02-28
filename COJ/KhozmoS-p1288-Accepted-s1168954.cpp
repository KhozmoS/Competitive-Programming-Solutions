#include <iostream>

using namespace std;

int main()
{
    string a;
    int b, c=0;
    cin >> b;
    while (b--){
    ;
    c = 0;
    cin >> a;
    for (int i=0; i<a.size(); i++){
    c+=a[i]-'0';
    }
    if (c%3==0 && (a[a.size()-1]-'0')%2==0)
    cout << "YES\n";
    else
    cout << "NO\n";
    }
    return 0;
}
