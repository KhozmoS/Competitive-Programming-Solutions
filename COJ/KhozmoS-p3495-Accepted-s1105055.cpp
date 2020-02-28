#include <bits/stdc++.h>

using namespace std;


const int MAX = 25;

string ans[] = {"Hydrogen", "Helium", "Lithium", "Beryllium", "Boron", "Carbon", "Nitrogen", "Oxygen", "Fluorine", "Neon", "Sodium", "Magnesium", "Aluminum", "Silicon", "Phosphorus", "Sulfur", "Chlorine", "Argon", "Potassium", "Calcium"};
string per[] = {"H", "He", "Li", "Be", "B", "C", "N", "O", "F", "Ne", "Na", "Mg", "Al", "Si", "P", "S", "Cl", "Ar", "K", "Ca"};
int freq[MAX];

map <string , int> pos;

queue <int> cola;
vector <int >adl[MAX];
bool mk[MAX];




int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    for(int i = 0 ; i < 20 ; i++) pos[per[i]] = i;

    int t;
    cin>>t;


    for(int cas = 1 ; t-- ; cas++)
    {
        string form;
        cin>>form;
        form += "X";
        for(int i = 0 ;i < form.size() - 1; i++)
        {
            if(isupper(form[i]))
            {
                if(islower(form[i + 1]))
                {
                    int num = 1;
                    if(form[i + 2] >= '0' && form[i + 2] <= '9')
                        num = (form[i + 2] - '0');

                    string ver = "";
                    ver += form[i];
                    ver += form[i + 1];
                    freq[pos[ver]] += num;
                }
                else{
                int num = 1;
                    if(form[i + 1] >= '0' && form[i + 1] <= '9')
                        num = (form[i + 1] - '0');

                    string ver = "";
                    ver += form[i];
                    freq[pos[ver]] += num;
            }
            }
        }
        cout<<"Case #"<<cas<<":\n";
        for(int i = 0 ; i < 20 ; i++)
        {
            if(freq[i])
                cout<<freq[i]<<" "<<ans[i]<<"\n";
            freq[i] = 0;
        }
    }

    return 0;
}
