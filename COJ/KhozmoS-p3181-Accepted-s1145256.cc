#include <bits/stdc++.h>
#include <algorithm>
#include <vector>
#define FOR(i,n) for(int i = 0; i < n; i++)
#define ll long long
#define endl '\n'
#define MAXN 10002
#define eps 1>>30
#define mod 1000003

using namespace std;

bool tabla[25][25];
struct TEAM
{
    string nombre;
    int id;
    int JG;
    int JP;
    int CA;
    int CP;
    //TEAM()
    //TEAM(string nombre, int JG, int CA, int CP): nombre(nombre), JG(JG), CA(CA), CP(CP){}
} arr[25];

bool operator<(const TEAM &a, const TEAM &b)
{
    if(a.JG==b.JG)
    {
        if(a.CP==b.CP)
        {
            if(a.CA==b.CA)
            {
                return tabla[a.id][b.id];
            }else{
                return a.CA>b.CA;
            }
        }else{
            return a.CP<b.CP;
        }
    }else{
        return a.JG>b.JG;
    }
}
string nombres[25];
string ps1,ps2,gs1,gs2, oro, plata, bronce;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    cin>>n;
    for(int i = 1; i <= n; i++)
    {
        arr[i].nombre="";
        arr[i].id=arr[i].JG=arr[i].JP = arr[i].CA =  arr[i].CP = 0;
    }
    int cant = n*(n-1)/2;
    for(int i= 1; i <= n; i++)
    {
        cin >> nombres[i];
        arr[i].nombre = nombres[i];
        arr[i].id = i;
    }
    int t1,c1,t2,c2;
    FOR(i, cant)
    {
        cin>>t1>>c1>>t2>>c2;
        //scanf("%d %d %d %d", &t1,&c1,&t2,&c2);
        if(c2>c1)
        {
            tabla[t2][t1] = true;
            tabla[t1][t2] = false;
            arr[t1].JP++;
            arr[t2].JG++;
            arr[t1].CA+=c1;
            arr[t1].CP+=c2;
            arr[t2].CA+=c2;
            arr[t2].CP+=c1;
        }else{
            tabla[t1][t2] = true;
            tabla[t2][t1] = false;
            arr[t2].JP++;
            arr[t1].JG++;
            arr[t2].CA+=c2;
            arr[t2].CP+=c1;
            arr[t1].CA+=c1;
            arr[t1].CP+=c2;
        }
    }
    sort(arr+1,arr+n+1);
    string final1, final2, bronce1, bronce2;
    int ID1, ID2, ID3, ID4;
    FOR(i, 1)
    {
        cin>>t1>>c1>>t2>>c2;
        //scanf("%d%d%d%d", &t1,&c1,&t2,&c2);
        t1 = arr[t1].id;
        t2 = arr[t2].id;
        ID1 = t1;
        ID2 = t2;
        if(c2>c1)
        {
            final1 = nombres[t2];
            bronce1 = nombres[t1];
        }else{
            final1 = nombres[t1];
            bronce1 = nombres[t2];
        }
    }
    FOR(i, 1)
    {
        cin>>t1>>c1>>t2>>c2;
        //scanf("%d%d%d%d", &t1,&c1,&t2,&c2);
        t1 = arr[t1].id;
        t2 = arr[t2].id;
        ID3 = t1;
        ID4 = t2;
        if(c2>c1)
        {
            final2 = nombres[t2];
            bronce2 = nombres[t1];
        }else{
            final2 = nombres[t1];
            bronce2 = nombres[t2];
        }
    }
    cin >> ps1 >> c1 >> ps2 >> c2;
    if(c1>c2)
    {
        bronce = bronce1;
    }else{
        bronce =  bronce2;
    }
    cin>>gs1>>c1>>gs2>>c2;
    if(c1>c2)
    {
        oro = final1;
        plata = final2;
    }else{
        oro =  final2;
        plata = final1;
    }
    cout <<"RANKING\n";
    cout<<"NAME JG JP CA CP\n";
    for(int i = 1; i <= n; i++)
    {
        cout << arr[i].nombre << " "<<arr[i].JG << " "<<arr[i].JP << " "<<arr[i].CA << " "<<arr[i].CP << '\n';
    }
    cout << "\n";
    cout << "SEMIFINAL 1: "<< nombres[ID1] << " vs "<<nombres[ID2]<<endl;
    cout << "GANADOR: "<<final1<<endl;
    cout << "SEMIFINAL 2: "<<nombres[ID3] << " vs "<<nombres[ID4]<<endl;
    cout <<"GANADOR: "<< final2<<endl<<endl;

    cout << "BRONCE: "<<bronce1 << " vs "<<bronce2<<endl;
    cout << "GANADOR: "<< bronce << endl;
    cout << "FINAL: "<<final1 << " vs "<<final2<<endl;
    cout << "GANADOR: "<<oro<<endl<<endl;

    cout << "ORO: "<<oro<<endl;
    cout << "PLATA: "<<plata<<endl;
    cout << "BRONCE: "<<bronce<<endl;
    return 0;
}
