#include<bits/stdc++.h>

using namespace std;

float n , k , m;
int main()
{
    cin>>n>>k;
    float mostrar = n / 2;
    if(k == 0)
        cout<<"0\n";
    else if(n <= 2)
        cout<<"-1\n";
    else if(k == 1 && n != 2)
        cout<<n<<"\n";
    else if(k < mostrar)
        cout<<n * k<<"\n";
    else
        cout<<"-1\n";
    //float mostrar = n / k;
   //  printf("%.2lf\n" , mostrar);
    return 0;
}
