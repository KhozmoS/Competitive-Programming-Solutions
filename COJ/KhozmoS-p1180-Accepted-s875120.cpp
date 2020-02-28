#include <bits/stdc++.h>

using namespace std;
 int K,Q,A,C,T,P;
int main()
{
    int N;
    cin>>N;
      for(int i=0;i<N;i++){
    cin>>K>>Q>>A>>C>>T>>P;
     int solk=(K-1)*(-1);
     int solq=(Q-1)*(-1);
     int sola=(A-2)*(-1);
     int solc=(C-2)*(-1);
     int solt=(T-2)*(-1);
     int solp=(P-8)*(-1);
    cout<<solk<<" "<<solq<<" "<<sola<<" "<<solc<<" "<<solt<<" "<<solp<<endl;
      }
    return 0;
}
