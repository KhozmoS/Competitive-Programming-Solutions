#include <stdio.h>
#include <algorithm>
using namespace std;
int m[ 102 ][ 102 ];
int main()
{
	int T, n;
	scanf("%d",&T);
	while ( T-- )
	{
		scanf("%d",&n);
		for (int i=0; i<n; i++)
			for (int j=0; j<=i; j++)
				scanf("%d",&m[i][j]);
		for (int i=n-2; i>=0; i--)
			for (int j=0; j<=i; j++)
				m[ i ][ j ] += max( m[i+1][j], m[i+1][j+1] );
		printf("%d\n",m[0][0]);
	}
	return 0;
}
