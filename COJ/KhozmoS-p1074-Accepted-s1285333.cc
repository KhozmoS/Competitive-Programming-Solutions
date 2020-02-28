#include <bits/stdc++.h>

using namespace std;

bool Mk[13][13];
int N ;

 void prin(int N ){
      for( int i= 1;i <= N ; i++)
         for(int j =1 ; j<= N ; j++){
                 if (Mk[i][j] == true )
                      cout << j << ' ';
                 }
 }


bool ok (int R , int C){
        bool falgR = true;

        for(int i = 1 ; i<= N ; i++)
                if(Mk[R][i] == true) falgR = false;

        for(int i = 1 ; i <= N ; i++)
                if(Mk[i][C])
                    falgR = false;

        int i = R;int j = C;
        while(i>=1 && j >= 1)
        {
            if(Mk[i][j]) return false;
            i--;j--;
        }
        i = R;j = C;
        while(i<=N && j<=N)
        {
            if(Mk[i][j]) return false;

            i++;j++;
        }
        i = R;j = C;
        while(i>=1 && j <= N)
        {
            if(Mk[i][j]) return false;
            i--;j++;
        }
        i = R;j = C;
        while(i<=N && j>=1)
        {
            if(Mk[i][j]) return false;

            i++;j--;
        }

        if(falgR) return true;


        return false;
}



int sol;

void solve (int pos){
      if(pos > N ){
        cout << ++sol << " : ";
          prin(N);
          cout << '\n';
         return ;
      }
    for(int i = 1 ; i <= N ;i++){
          if(ok(pos,i)){
                Mk[pos][i] = true;
                solve(pos+1);
                Mk[pos][i] = false;
          }
    }

}


int main()
{
  ios_base ::sync_with_stdio(0);
  cin.tie(NULL);


      while( cin >> N){
           solve(1);
           if(!sol) cout << "No Solution.\n";
           sol = 0;
        }
}
