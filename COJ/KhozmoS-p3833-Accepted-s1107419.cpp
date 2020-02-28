#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;
#define N 1000002
#define inf 1e9
int n;
int t;
double E[N];
int main(){

    int cas =0 ;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        E[n+1] = 0;
        for(int i =n;i>=1;i--){
            E[i] = (double) n/(n-i + 1) + E[i+1];
        }
        printf("%.2lf\n",E[1]);
    }
    return 0;
}
