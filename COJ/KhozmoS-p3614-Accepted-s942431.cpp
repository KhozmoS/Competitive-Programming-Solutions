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
    num[13] = "thirteen";
    num[14] = "fourteen";
    num[15] = "fifteen";
    num[16] = "sixteen";
    num[17] = "seventeen";
    num[18] = "eighteen";
    num[19] = "nineteen";

    num[20] = "twenty";
    num[30] = "thirty";
    num[40] = "forty";
    num[50] = "fifty";
    num[60] = "sixty";
    num[70] = "seventy";
    num[80] = "eighty";
    num[90] = "ninety";

    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        if(n < 20)
            cout << num[n] << "\n";
        else{
            if(n % 10 == 0)
                cout << num[n] << "\n";
            else
                cout << num[(n / 10) * 10] << "-" << num[n % 10] << "\n";
        }
    }



    return 0;
}
