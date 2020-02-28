#include<bits/stdc++.h>


using namespace std;
const int MAXN = 1005;
double arr[MAXN] , Q1 , Q3 , IQR;
//Q3 + 1.5 * IQR or below Q1 - 1.5 * IQR
int N;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>N;
    for(int i = 1 ; i <= N ; i++)
    cin>>arr[i];

    sort(arr + 1 , arr + N + 1);
    int m = N / 2;
    if(m % 2 == 0)
    Q1 = (arr[m / 2] + arr[m / 2 + 1]) / 2;
    else
    Q1 = arr[m / 2 + 1];
    if(N % 2 == 0)
    {
        if(m % 2 == 0)
        {
            Q3 = (arr[m + (m / 2)] + arr[m + (m / 2) + 1]) / 2;
        }
        else
        {
            Q3 = (arr[m + (m / 2) + 1]);
        }
    }
    else
    {
        // 1 2 3 4 5 6 7 8 9
        if(m % 2 == 1)
        {
            Q3 = (arr[m + (m / 2) + 2]);
        }
        else
        {
            Q3 = (arr[m + m/2 + 1] + arr[m + m/2 + 2]) / 2;
        }
    }
    //Q3 + 1.5 * IQR or below Q1 - 1.5 * IQR
     IQR = Q3 - Q1;
     int sol = 0;
     for(int i = 1 ; i <= N ; i++)
     {
         if(arr[i] > Q3 + 1.5 * IQR || arr[i] < Q1 - 1.5 * IQR)
         sol++;
     }
     cout<<sol<<"\n";
    return 0;
}
