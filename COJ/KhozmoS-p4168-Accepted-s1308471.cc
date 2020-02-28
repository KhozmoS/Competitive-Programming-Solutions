#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pb push_back
#define db double
#define all(c) (c).begin(),(c).end()
#define sz(c) (c).size()

typedef long long ll;
typedef pair <int , int> ii;
typedef pair <ii , int> iii;
typedef vector <int >vi;
typedef vector <ii> vii;
typedef vector <vi> vvi;
typedef vector <vii> vvii;

const ll mod = 1e9+7;
const int MAX = 1e6+5;
char ans[MAX];
char A[MAX];
char B[MAX];



int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);

    int n;scanf("%d" , &n);

    scanf("%s" , A);
    scanf("%s" , B);

    int CA = n/2;
    int CB = n/2;
    int tie = 0;

    for(int i = 0 ; i < n ; i++)
    {
        if(A[i] == B[i])
        {
            tie++;
            ans[i] = A[i];
        }
        else if(A[i]<B[i] && CA)
        {
            CA--;
            ans[i] = A[i];
        }
        else if(A[i]>B[i] && CB || (!CA))
        {
            CB--;
            ans[i] = B[i];
        }
        else{
            CA--;
            ans[i] = A[i];
        }
    }
    printf("%s" , ans );
}
