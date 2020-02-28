#include <iostream>
#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    lli T, num, n;
    double a = 0, b = 0;

    cin >>n;
    while(n--){
        cin >>num;
        a += log10((double)num);
    }

    cin >>n;
    while(n--){
        cin >>num;
        b += log10((double)num);
    }
    if(a > b){
        cout <<">";
    }else if(a < b){
        cout <<"<";
    }else{
        cout <<"=";
    }
}
