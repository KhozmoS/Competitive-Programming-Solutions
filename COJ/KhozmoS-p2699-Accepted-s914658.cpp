    #include<bits/stdc++.h>

    using namespace std;
    //long long t , n , sol = 1 , ad = 0;
    double sum ;
    double sol;
    int t = 30;
    int x;
    int main()
    {
        //ios_base::sync_with_stdio(0);cin.tie(0);
        while(t--)
        {
         scanf("%d" , &x);
         sum += x;
        }
       sol = sum / 30;
       //cout<<sum<<"\n";
        printf("%.3lf\n" , sum + sol);
     return 0;
    }
