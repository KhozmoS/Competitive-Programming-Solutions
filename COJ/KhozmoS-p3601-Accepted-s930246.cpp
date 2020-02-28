#include<bits/stdc++.h>

using namespace std;
  int N;
 string sol[] = {"" , "one" , "two" , "three" , "four" , "five" , "six" , "seven" , "eight" , "nine" , "ten" , "eleven" , "twelve"};
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>N;
    while(N--)
    {
        int pos;
        cin>>pos;
        cout<<sol[pos]<<"\n";
    }


    return 0;
}
