#include <bits/stdc++.h>

using namespace std;

int main()
{
int A[1001];
int n;
cin>>n;
int ind=1;
while(ind<=n)
{
cin>>A[ind];
ind++;
}

sort(A + 1, A + n + 1);


ind = 1;
 while(ind<=n)
{cout<<A[ind]<<endl;
ind++;}



	return 0;

}
