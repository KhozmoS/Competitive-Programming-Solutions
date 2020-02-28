#include <iostream>

using namespace std;

string num[120];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    num[0] = "zero";
    num[1] = "one";
    num[2] = "two";
    num[3] = "three";
    num[4] = "four";
    num[5] = "five";
    num[6] = "six";
    num[7] = "seven";
    num[8] = "eight";
    num[9] = "nine";
    num[10] = "ten";
    num[11] = "eleven";
    num[12] = "twelve";

    int n;
    cin >> n;
    cout<<num[n].size();
    return 0;
}
