#include <bits/stdc++.h>
//by KhozmoS
using namespace std;

char cad[900000], c;

int main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0);

    int t;
    cin >> t;
    scanf("%c", &c);
    while(t--)
    {

        //string cad;
        //getline(cin, cad);
         scanf("%[^\n]", cad);scanf("%c", &c);
        //scanf("%c", c);
        for(int i = 0; i < strlen(cad); i++)
            if(isupper(cad[i]))
                cad[i] = tolower(cad[i]);
            else if(islower(cad[i]))
                cad[i] = toupper(cad[i]);
        printf("%s\n", cad);
    }
    return 0;
}