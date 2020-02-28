#include<bits/stdc++.h>


using namespace std;
const int MAXN = 2050;
const int MAXP = 13;
double A[MAXN];
double AUX[MAXN];
int it , N;
int pote[MAXP];
void pot()
{
    //int e = 0;
    for(int i = 0 ; i < MAXP ; i++)
    pote[i] = pow(2 , i);
}

/*
8
38.75 -26.75 -3 -52.5 -3 0 1 2
*/
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    pot();
    //for(int i = 0 ; i < 13 ; i++)
    //cout<<pote[i]<<endl;
    cin>>N;
    int R = N;
    while(R != 1)
    {
        R /= 2;
        it++;
    }
    for(int i = 1 ; i <= N ; i++){
    double x;
    cin>>x;
    A[i] = x;
    }
    for(int i = 1 ; i <= N ; i++)
    AUX[i] = A[i];
   // cout<<it<<"\n";
    int t = 1;
    int e = 0;
    while(it)
    {
        int pos = 1;
        for(int i = 1 ; i <= t ; i++)
        {
            int x = i + pote[e];
            AUX[pos] = (A[i] + A[x]);
            AUX[pos + 1] = (A[i] - A[x]);
            pos += 2;
        }
          for(int i = 1 ; i <= N ; i++){
          A[i] = AUX[i];
          }

          //it
         t += pote[e]; e++;it--;
    }
     for(int i = 1 ; i < N ; i++)
     cout<<A[i]<<" ";
     cout<<A[N]<<"\n";
    return 0;

}
