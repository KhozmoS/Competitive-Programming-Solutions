#include<bits/stdc++.h>

#define MAX 2000 + 5

using namespace std;

int n;
int a[MAX];


bool ver(int l,int r){
	for(int i = r - 1; i >= l; i--){
		if(__gcd(a[r],a[i]) != 1)
			return false;
	}
	return true;
}

int main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

	scanf("%d",&n);
	for(int i = 0 ; i < n; i++)
		scanf("%d",&a[i]);
	int l = 0;
	int r = 0;
	
	int ans = 0;
	
	while(r < n){
		if(ver(l,r)){
			ans = max(ans , r - l + 1);
			r++;
		}
		else{
			l++;
		}
	}
	
	printf("%d\n",ans);

}
