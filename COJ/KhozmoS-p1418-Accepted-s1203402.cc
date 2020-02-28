#include <bits/stdc++.h>

using namespace std;

string txt;

int main()
{
  //cout<<'z'-0;
  ios_base::sync_with_stdio(0);cin.tie(0);

  while(getline(cin , txt))
  {
     string word = "";
     for(int i = 0 ; i < txt.size() ; i++)
     {
         if((txt[i] >= 65 && txt[i] <= 90) || (txt[i] >= 97 && txt[i] <= 122)){
              word += txt[i];

              if(i == ((int)(txt.size()-1))){
                  if(word.size()==1){
                        cout<<"Si estan mal los juegos de datos estan mal";
                        continue;
                  }
                    if(word[0] == 'A' || word[0] == 'a' || word[0] == 'E' || word[0] == 'e' || word[0] == 'I'||
                       word[0] == 'i' || word[0] == 'O' || word[0] == 'o' || word[0] == 'U' || word[0] == 'u')
                    {
                            word += "ay";
                            cout<<word;
                    }
              else{
                    for(int i = 1 ; i < word.size() ;++i)cout<<word[i];
                    cout<<word[0]<<"ay";
              }
              }
         }
         else{
              if(word.size()==0){
                cout<<txt[i];continue;
              }
              if(word[0] == 'A' || word[0] == 'a' || word[0] == 'E' || word[0] == 'e' || word[0] == 'I'||
                 word[0] == 'i' || word[0] == 'O' || word[0] == 'o' || word[0] == 'U' || word[0] == 'u')
              {
                  word += "ay";
                  cout<<word+txt[i];
              }
              else{
                  for(int i = 1 ; i < word.size() ;++i)cout<<word[i];
                  cout<<word[0]<<"ay"<<txt[i];
              }
              word = "";
         }
     }
     cout<<"\n";
     txt = "";
  }
}
