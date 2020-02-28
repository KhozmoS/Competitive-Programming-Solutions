#include <bits/stdc++.h>

using namespace std;
vector <string> arr;
/*
    3 white balls represent "scissors"
    3 blue balls represent "rock"
    2 balls of one color and 1 ball of another color always represent "paper" for Bianka.
    2 blue balls and 1 white ball represent "rock" for Williams
    2 white balls and 1 blue ball represent "scissors" for Williams
    always rock win to scissors, scissors win to paper, paper win to rock.
*/
string B , W;
int cb , cn;

string tirob ;
 string tirow;
int main()
{
    //ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
    //cin>>t;

    cb = 0; cn = 0;
    cin>>B;
    cin>>W;
    for(int i = 0 ; i < 3 ; i++)
    {
        if(B[i] == 'W')
        cb++;
        if(B[i] == 'B')
        cn++;
    }
      //cout<<cb<<" "<<cn<<"\n";
      if(cb == 3) tirob = "scissors";

      else if(cn == 3) tirob = "rock";

      else tirob = "paper";
      cb = 0;
      cn = 0;
      for(int i = 0 ; i < 3 ; i++)
      {
        if(W[i] == 'W')
        cb++;
        if(W[i] == 'B')
        cn++;
      }
      //cout<<cb<<" "<<cn<<"\n";
      if(cb == 3) tirow = "scissors";
      if(cn == 3) tirow = "rock";
      if(cb == 2 && cn == 1) tirow =  "scissors";
      if(cb == 1 && cn == 2) tirow = "rock";
        //cout<<tirob<<" "<<tirow<<"\n";
      if(tirob[0] == 's' && tirow[0] == 'p'){
      cout<<"Bianka won with Scissors\n";
      cout<<"Williams lost with Paper\n";
      }
      if(tirob[0] == 'p' && tirow[0] == 'r')
      {
       cout<<"Bianka won with Paper\n";
       cout<<"Williams lost with Rock\n";
      }
      if(tirob[0] == 'r' && tirow[0] == 's')
      {
       cout<<"Bianka won with Rock\n";
       cout<<"Williams lost with Scissors\n";
      }
      if(tirow[0] == 's' && tirob[0] == 'p'){
      cout<<"Williams won with Scissors\n";
      cout<<"Bianka lost with Paper\n";
      }
      if(tirow[0] == 'p' && tirob[0] == 'r')
      {
       cout<<"Williams won with Paper\n";
       cout<<"Bianka lost with Rock\n";
      }
      if(tirow[0] == 'r' && tirob[0] == 's')
      {
       cout<<"Williams won with Rock\n";
       cout<<"Bianka lost with Scissors\n";
      }

    return 0;
}
