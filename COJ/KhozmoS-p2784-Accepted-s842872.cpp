
#include <bits/stdc++.h>

using namespace std;

int main()
{
int A[10001];
int n;
scanf("%d", &n);
int ind=1;
while(ind<=n)
{
scanf("%d", &A[ind]);
ind++;
}

sort(A + 1, A + n + 1);


ind = 1;
printf("%d", A[n]);
 while(ind<=n - 1)
{
 printf(" %d", A[ind]);
 ind++;
 }
 printf("\n");



	return 0;

}
